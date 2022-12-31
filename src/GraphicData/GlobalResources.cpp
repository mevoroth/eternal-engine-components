#include "GraphicData/GlobalResources.hpp"
#include "GraphicData/RenderTargetTexture.hpp"
#include "Camera/Camera.hpp"
#include "Core/System.hpp"
#include "Types/Types.hpp"
#include "HLSLPerViewConstants.hpp"

namespace Eternal
{
	namespace GraphicData
	{
		using namespace Eternal::Types;
		using namespace Eternal::HLSL;

		GlobalResources::GlobalResources(_In_ GraphicsContext& InContext)
		{
			_ViewConstantBuffer = CreateMultiBufferedBuffer(
				InContext,
				BufferResourceCreateInformation(
					InContext.GetDevice(),
					"ViewConstantBuffer",
					BufferCreateInformation(
						Format::FORMAT_UNKNOWN,
						BufferResourceUsage::BUFFER_RESOURCE_USAGE_CONSTANT_BUFFER,
						sizeof(PerViewConstants)
					),
					ResourceMemoryType::RESOURCE_MEMORY_TYPE_GPU_UPLOAD
				)
			);

			ViewMetaData MetaData;
			MetaData.ConstantBufferView.BufferSize = sizeof(PerViewConstants);
			_ViewConstantBufferView = CreateMultiBufferedConstantBufferView(
				*_ViewConstantBuffer,
				ConstantBufferViewCreateInformation(
					InContext,
					*_ViewConstantBuffer,
					MetaData
				)
			);

			_GBufferLuminance = new RenderTargetTexture(
				InContext,
				TextureResourceCreateInformation(
					InContext.GetDevice(),
					"GBufferEmissive",
					TextureCreateInformation(
						ResourceDimension::RESOURCE_DIMENSION_TEXTURE_2D,
						Format::FORMAT_RGB111110_FLOAT,
						TextureResourceUsage::TEXTURE_RESOURCE_USAGE_SHADER_RESOURCE | TextureResourceUsage::TEXTURE_RESOURCE_USAGE_RENDER_TARGET | TextureResourceUsage::TEXTURE_RESOURCE_USAGE_UNORDERED_ACCESS,
						InContext.GetWindow().GetWidth(),
						InContext.GetWindow().GetHeight()
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
						InContext.GetWindow().GetWidth(),
						InContext.GetWindow().GetHeight()
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
						InContext.GetWindow().GetWidth(),
						InContext.GetWindow().GetHeight()
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
						InContext.GetWindow().GetWidth(),
						InContext.GetWindow().GetHeight()
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
						InContext.GetWindow().GetWidth(),
						InContext.GetWindow().GetHeight(),
						1,
						1,
						TextureCreateInformation::DefaultClearValueDepth
					),
					ResourceMemoryType::RESOURCE_MEMORY_TYPE_GPU_MEMORY,
					TransitionState::TRANSITION_DEPTH_STENCIL_WRITE
				),
				RenderTargetTextureFlags::RENDER_TARGET_TEXTURE_FLAGS_GRAPHICS
			);

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
		}

		GlobalResources::~GlobalResources()
		{
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

			DestroyMultiBufferedView(_ViewConstantBufferView);
			DestroyMultiBufferedResource(_ViewConstantBuffer);
		}

		bool GlobalResources::BeginRender(_In_ GraphicsContext& InContext, _In_ System& InSystem)
		{
			Components::Camera* CurrentCamera = InSystem.GetRenderFrame().View;
			bool CanRender = CurrentCamera != nullptr;
			if (CanRender)
			{
				MapRange ViewBufferRange(sizeof(PerViewConstants));
				MapScope<PerViewConstants> ViewBufferMapScope(**_ViewConstantBuffer, ViewBufferRange);
				PerViewConstants* ViewConstantsPointer = ViewBufferMapScope.GetDataPointer();

				CurrentCamera->GetWorldToClip(ViewConstantsPointer->WorldToClip);
				CurrentCamera->GetClipToWorld(ViewConstantsPointer->ClipToWorld);
				CurrentCamera->GetWorldToView(ViewConstantsPointer->WorldToView);
				CurrentCamera->GetViewToWorld(ViewConstantsPointer->ViewToWorld);
				CurrentCamera->GetViewToClip(ViewConstantsPointer->ViewToClip);
				CurrentCamera->GetClipToView(ViewConstantsPointer->ClipToView);
				ViewConstantsPointer->ViewPosition				= Vector4(CurrentCamera->GetPosition(), 1.0f);
				ViewConstantsPointer->ViewForward				= Vector4(CurrentCamera->GetForward(), 0.0f);
				ViewConstantsPointer->ScreenSizeAndInverseSize	= Vector4(
					static_cast<float>(InContext.GetWindow().GetWidth()),
					static_cast<float>(InContext.GetWindow().GetHeight()),
					1.0f / static_cast<float>(InContext.GetWindow().GetWidth()),
					1.0f / static_cast<float>(InContext.GetWindow().GetHeight())
				);
				ViewConstantsPointer->RenderNearPlane	= CurrentCamera->GetRenderNear();
				ViewConstantsPointer->RenderFarPlane	= CurrentCamera->GetRenderFar();
			}
			return CanRender;
		}
	}
}
