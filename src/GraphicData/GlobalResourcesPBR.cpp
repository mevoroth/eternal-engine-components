#include "GraphicData/GlobalResourcesPBR.hpp"
#include "Camera/PerspectiveCamera.hpp"
#include "Core/System.hpp"
#include "GraphicData/ViewGraphicData.hpp"

namespace Eternal
{
	namespace GraphicData
	{
		GlobalResourcesPBR::GlobalResourcesPBR(_In_ GraphicsContext& InContext)
			: GlobalResources(InContext)
		{
			_GBufferAlbedo = new RenderTargetTexture(
				InContext,
				TextureResourceCreateInformation(
					InContext.GetDevice(),
					"GBufferAlbedo",
					TextureCreateInformation(
						ResourceDimension::RESOURCE_DIMENSION_TEXTURE_2D,
						Format::FORMAT_RGBA8888_UNORM,
						TextureResourceUsage::TEXTURE_RESOURCE_USAGE_SHADER_RESOURCE | TextureResourceUsage::TEXTURE_RESOURCE_USAGE_RENDER_TARGET,
						InContext.GetOutputDevice().GetWidth(),
						InContext.GetOutputDevice().GetHeight()
					),
					ResourceMemoryType::RESOURCE_MEMORY_TYPE_GPU_MEMORY,
					TransitionState::TRANSITION_RENDER_TARGET
				),
				RenderTargetTextureFlags::RENDER_TARGET_TEXTURE_FLAGS_GRAPHICS
			);

			_GBufferNormals = new RenderTargetTexture(
				InContext,
				TextureResourceCreateInformation(
					InContext.GetDevice(),
					"GBufferNormals",
					TextureCreateInformation(
						ResourceDimension::RESOURCE_DIMENSION_TEXTURE_2D,
						Format::FORMAT_RGBA8888_SNORM,
						TextureResourceUsage::TEXTURE_RESOURCE_USAGE_SHADER_RESOURCE | TextureResourceUsage::TEXTURE_RESOURCE_USAGE_RENDER_TARGET,
						InContext.GetOutputDevice().GetWidth(),
						InContext.GetOutputDevice().GetHeight()
					),
					ResourceMemoryType::RESOURCE_MEMORY_TYPE_GPU_MEMORY,
					TransitionState::TRANSITION_RENDER_TARGET
				),
				RenderTargetTextureFlags::RENDER_TARGET_TEXTURE_FLAGS_GRAPHICS
			);

			_GBufferRoughnessMetallicSpecular = new RenderTargetTexture(
				InContext,
				TextureResourceCreateInformation(
					InContext.GetDevice(),
					"GBufferRoughnessMetallicSpecular",
					TextureCreateInformation(
						ResourceDimension::RESOURCE_DIMENSION_TEXTURE_2D,
						Format::FORMAT_RGBA8888_UNORM,
						TextureResourceUsage::TEXTURE_RESOURCE_USAGE_SHADER_RESOURCE | TextureResourceUsage::TEXTURE_RESOURCE_USAGE_RENDER_TARGET,
						InContext.GetOutputDevice().GetWidth(),
						InContext.GetOutputDevice().GetHeight()
					),
					ResourceMemoryType::RESOURCE_MEMORY_TYPE_GPU_MEMORY,
					TransitionState::TRANSITION_RENDER_TARGET
				),
				RenderTargetTextureFlags::RENDER_TARGET_TEXTURE_FLAGS_GRAPHICS
			);

			{
				_ShadowMapViewConstantBuffer = new ConstantBuffer<PerViewConstants>(InContext, "ShadowMapViewBuffer");
				_ShadowMap = new RenderTargetTexture(
					InContext,
					TextureResourceCreateInformation(
						InContext.GetDevice(),
						"ShadowMap",
						TextureCreateInformation(
							ResourceDimension::RESOURCE_DIMENSION_TEXTURE_2D,
							Format::FORMAT_D32,
							TextureResourceUsage::TEXTURE_RESOURCE_USAGE_SHADER_RESOURCE | TextureResourceUsage::TEXTURE_RESOURCE_USAGE_DEPTH_STENCIL,
							4096,
							4096,
							1,
							1,
							TextureCreateInformation::DefaultClearValueDepth
						),
						ResourceMemoryType::RESOURCE_MEMORY_TYPE_GPU_MEMORY,
						TransitionState::TRANSITION_DEPTH_STENCIL_WRITE
					),
					RenderTargetTextureFlags::RENDER_TARGET_TEXTURE_FLAGS_GRAPHICS
				);

				_ShadowMapViewport = CreateViewport(InContext, 4096, 4096);
			}

			{
				_AtmosphereConstantBuffer		= new ConstantBuffer<AtmosphereConstants>(InContext, "AtmosphereBuffer");
				_SkyViewCubeMapConstantBuffer	= new ConstantBuffer<PerViewCubeMapConstants>(InContext, "SkyViewCubeMapBuffer");

				uint32_t SkyCubeMapMipCount = static_cast<uint32_t>(Math::Log2<float>(SkyCubeMapSize)) + 1;

				_Sky = new RenderTargetTexture(
					InContext,
					TextureResourceCreateInformation(
						InContext.GetDevice(),
						"Sky",
						TextureCreateInformation(
							ResourceDimension::RESOURCE_DIMENSION_TEXTURE_CUBE,
							Format::FORMAT_RGB111110_FLOAT,
							TextureResourceUsage::TEXTURE_RESOURCE_USAGE_SHADER_RESOURCE | TextureResourceUsage::TEXTURE_RESOURCE_USAGE_RENDER_TARGET | TextureResourceUsage::TEXTURE_RESOURCE_USAGE_UNORDERED_ACCESS,
							SkyCubeMapSize,
							SkyCubeMapSize,
							6,
							SkyCubeMapMipCount
						),
						ResourceMemoryType::RESOURCE_MEMORY_TYPE_GPU_MEMORY,
						TransitionState::TRANSITION_RENDER_TARGET
					),
					RenderTargetTextureFlags::RENDER_TARGET_TEXTURE_FLAGS_ALL
				);

				_SkyMipShaderResourceViews.resize(SkyCubeMapMipCount);
				_SkyMipUnorderedAccessViews.resize(SkyCubeMapMipCount);

				auto CreateMipView = [this, &InContext](_In_ uint32_t InSkyMipIndex) -> void
				{
					ViewMetaData MetaData;
					MetaData.ShaderResourceViewTexture2DArray.MostDetailedMip	= InSkyMipIndex;
					MetaData.ShaderResourceViewTexture2DArray.MipLevels			= 1;
					MetaData.ShaderResourceViewTexture2DArray.FirstArraySlice	= 0;
					MetaData.ShaderResourceViewTexture2DArray.ArraySize			= 6;

					ShaderResourceViewCreateInformation SkyMipShaderResourceViewInformation(
						InContext,
						&_Sky->GetTexture(),
						MetaData,
						Format::FORMAT_RGB111110_FLOAT,
						ViewShaderResourceType::VIEW_SHADER_RESOURCE_TEXTURE_2D_ARRAY
					);
					_SkyMipShaderResourceViews[InSkyMipIndex] = CreateShaderResourceView(SkyMipShaderResourceViewInformation);
				};

				CreateMipView(0);
				_SkyMipUnorderedAccessViews[0] = _Sky->GetUnorderedAccessView();
				for (uint32_t SkyMipIndex = 1; SkyMipIndex < _SkyMipUnorderedAccessViews.size(); ++SkyMipIndex)
				{
					CreateMipView(SkyMipIndex);
					{
						ViewMetaData MetaData;
						MetaData.UnorderedAccessViewTexture2DArray.MipSlice			= SkyMipIndex;
						MetaData.UnorderedAccessViewTexture2DArray.ArraySize		= 6;

						UnorderedAccessViewCreateInformation SkyMipUnorderedAccessViewInformation(
							InContext,
							&_Sky->GetTexture(),
							MetaData,
							Format::FORMAT_RGB111110_FLOAT,
							ViewUnorderedAccessType::VIEW_UNORDERED_ACCESS_TEXTURE_2D_ARRAY
						);
						_SkyMipUnorderedAccessViews[SkyMipIndex] = CreateUnorderedAccessView(SkyMipUnorderedAccessViewInformation);
					}
				}

				_SkyViewport = CreateViewport(InContext, SkyCubeMapSize, SkyCubeMapSize);
			}
		}

		GlobalResourcesPBR::~GlobalResourcesPBR()
		{
			DestroyViewport(_SkyViewport);

			delete _Sky;
			_Sky = nullptr;

			delete _SkyViewCubeMapConstantBuffer;
			_SkyViewCubeMapConstantBuffer = nullptr;

			delete _AtmosphereConstantBuffer;
			_AtmosphereConstantBuffer = nullptr;

			DestroyViewport(_ShadowMapViewport);

			delete _ShadowMap;
			_ShadowMap = nullptr;

			delete _ShadowMapViewConstantBuffer;
			_ShadowMapViewConstantBuffer = nullptr;

			delete _GBufferRoughnessMetallicSpecular;
			_GBufferRoughnessMetallicSpecular = nullptr;

			delete _GBufferNormals;
			_GBufferNormals = nullptr;
			
			delete _GBufferAlbedo;
			_GBufferAlbedo = nullptr;
		}

		bool GlobalResourcesPBR::BeginRender(_In_ GraphicsContext& InContext, _In_ System& InSystem)
		{
			Components::Camera* CurrentCamera = InSystem.GetRenderFrame().ViewCamera;
			bool CanRender = CurrentCamera != nullptr;
			if (GlobalResources::BeginRender(InContext, InSystem))
			{
				MapRange SkyViewCubeMapBufferRange(sizeof(PerViewCubeMapConstants));
				MapScope<PerViewCubeMapConstants> SkyViewCubeMapBufferMapScope(*_SkyViewCubeMapConstantBuffer->GetResource(), SkyViewCubeMapBufferRange);

				Vector3 FacesForward[] =
				{
					Vector3::Right,
					Vector3::Left,
					Vector3::Up,
					Vector3::Down,
					Vector3::Forward,
					Vector3::Backward
				};
				ETERNAL_STATIC_ASSERT(ETERNAL_ARRAYSIZE(FacesForward) == VIEW_CUBE_MAP_FACE_COUNT, "Incorrect entries count for FacesForward");

				Vector3 FacesUp[] =
				{
					Vector3::Up,
					Vector3::Up,
					Vector3::Backward,
					Vector3::Forward,
					Vector3::Up,
					Vector3::Up
				};
				ETERNAL_STATIC_ASSERT(ETERNAL_ARRAYSIZE(FacesUp) == VIEW_CUBE_MAP_FACE_COUNT, "Incorrect entries count for FacesUp");

				for (int FaceIndex = 0; FaceIndex < VIEW_CUBE_MAP_FACE_COUNT; ++FaceIndex)
				{
					PerspectiveCamera FaceCamera(CurrentCamera->GetNear(), /*CurrentCamera->GetFar()*/6431.0f, PI * 0.5f, 1.0f);
					FaceCamera.SetPosition(CurrentCamera->GetPosition() * M_TO_KM);
					FaceCamera.SetForward(FacesForward[FaceIndex]);
					FaceCamera.SetUp(FacesUp[FaceIndex]);
					UploadViewCameraToBuffer(&SkyViewCubeMapBufferMapScope->PerViewFace[FaceIndex], &FaceCamera, SkyCubeMapSize, SkyCubeMapSize);
				}
			}

			return false;
		}
	}
}
