#include "GraphicData/GlobalResources.hpp"
#include "GraphicData/ViewGraphicData.hpp"
#include "Camera/Camera.hpp"
#include "Camera/PerspectiveCamera.hpp"
#include "Core/System.hpp"
#include "Types/Types.hpp"
#include "Math/Math.hpp"
#include "ShadersReflection/HLSLPerViewConstants.hpp"

namespace Eternal
{
	namespace GraphicData
	{
		using namespace Eternal::Types;
		using namespace Eternal::HLSL;

		GlobalResources::GlobalResources(_In_ GraphicsContext& InContext)
			: _ViewConstantBuffer(InContext, "ViewConstantBuffer")
			, _ShadowMapViewConstantBuffer(InContext, "ShadowMapViewBuffer")
			, _AtmosphereConstantBuffer(InContext, "AtmosphereBuffer")
			, _SkyViewCubeMapConstantBuffer(InContext, "SkyViewCubeMapBuffer")
		{
			_GBufferLuminance = new RenderTargetTexture(
				InContext,
				TextureResourceCreateInformation(
					InContext.GetDevice(),
					"GBufferEmissive",
					TextureCreateInformation(
						ResourceDimension::RESOURCE_DIMENSION_TEXTURE_2D,
						Format::FORMAT_RGB111110_FLOAT,
						TextureResourceUsage::TEXTURE_RESOURCE_USAGE_SHADER_RESOURCE | TextureResourceUsage::TEXTURE_RESOURCE_USAGE_RENDER_TARGET | TextureResourceUsage::TEXTURE_RESOURCE_USAGE_UNORDERED_ACCESS,
						InContext.GetOutputDevice().GetWidth(),
						InContext.GetOutputDevice().GetHeight()
					),
					ResourceMemoryType::RESOURCE_MEMORY_TYPE_GPU_MEMORY,
					TransitionState::TRANSITION_RENDER_TARGET
				),
				RenderTargetTextureFlags::RENDER_TARGET_TEXTURE_FLAGS_ALL
			);

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

			_GBufferDepthStencil = new RenderTargetTexture(
				InContext,
				TextureResourceCreateInformation(
					InContext.GetDevice(),
					"GBufferDepthStencil",
					TextureCreateInformation(
						ResourceDimension::RESOURCE_DIMENSION_TEXTURE_2D,
						Format::FORMAT_DS328,
						TextureResourceUsage::TEXTURE_RESOURCE_USAGE_SHADER_RESOURCE | TextureResourceUsage::TEXTURE_RESOURCE_USAGE_DEPTH_STENCIL,
						InContext.GetOutputDevice().GetWidth(),
						InContext.GetOutputDevice().GetHeight(),
						1,
						1,
						TextureCreateInformation::DefaultClearValueDepth
					),
					ResourceMemoryType::RESOURCE_MEMORY_TYPE_GPU_MEMORY,
					TransitionState::TRANSITION_DEPTH_STENCIL_WRITE
				),
				RenderTargetTextureFlags::RENDER_TARGET_TEXTURE_FLAGS_GRAPHICS
			);

			{
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
				_Sky = new RenderTargetTexture(
					InContext,
					TextureResourceCreateInformation(
						InContext.GetDevice(),
						"Sky",
						TextureCreateInformation(
							ResourceDimension::RESOURCE_DIMENSION_TEXTURE_CUBE,
							Format::FORMAT_RGB111110_FLOAT,
							TextureResourceUsage::TEXTURE_RESOURCE_USAGE_SHADER_RESOURCE | TextureResourceUsage::TEXTURE_RESOURCE_USAGE_RENDER_TARGET,
							SkyCubeMapSize,
							SkyCubeMapSize,
							6,
							static_cast<uint32_t>(Math::Log2<float>(SkyCubeMapSize)) + 1
						),
						ResourceMemoryType::RESOURCE_MEMORY_TYPE_GPU_MEMORY,
						TransitionState::TRANSITION_RENDER_TARGET
					),
					RenderTargetTextureFlags::RENDER_TARGET_TEXTURE_FLAGS_GRAPHICS
				);

				_SkyViewport = CreateViewport(InContext, SkyCubeMapSize, SkyCubeMapSize);
			}
		}

		GlobalResources::~GlobalResources()
		{
			DestroyViewport(_SkyViewport);

			delete _Sky;
			_Sky = nullptr;

			DestroyViewport(_ShadowMapViewport);

			delete _ShadowMap;
			_ShadowMap = nullptr;

			delete _GBufferDepthStencil;
			_GBufferDepthStencil = nullptr;

			delete _GBufferLuminance;
			_GBufferLuminance = nullptr;

			delete _GBufferAlbedo;
			_GBufferAlbedo = nullptr;

			delete _GBufferNormals;
			_GBufferNormals = nullptr;

			delete _GBufferRoughnessMetallicSpecular;
			_GBufferRoughnessMetallicSpecular = nullptr;
		}

		bool GlobalResources::BeginRender(_In_ GraphicsContext& InContext, _In_ System& InSystem)
		{
			using namespace Eternal::Math;

			Components::Camera* CurrentCamera = InSystem.GetRenderFrame().ViewCamera;
			bool CanRender = CurrentCamera != nullptr;
			if (CanRender)
			{
				UploadViewCameraToBuffer(
					**_ViewConstantBuffer.ResourceBuffer,
					CurrentCamera,
					static_cast<float>(InContext.GetOutputDevice().GetWidth()),
					static_cast<float>(InContext.GetOutputDevice().GetHeight())
				);

				{
					MapRange SkyViewCubeMapBufferRange(sizeof(PerViewCubeMapConstants));
					MapScope<PerViewCubeMapConstants> SkyViewCubeMapBufferMapScope(*_SkyViewCubeMapConstantBuffer.ResourceBuffer, SkyViewCubeMapBufferRange);

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
			}
			return CanRender;
		}
	}
}
