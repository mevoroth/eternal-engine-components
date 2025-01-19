#include "GraphicData/GlobalResources.hpp"
#include "GraphicData/ViewGraphicData.hpp"
#include "Camera/Camera.hpp"
#include "Graphics/GraphicsContext.hpp"
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

		}

		GlobalResources::~GlobalResources()
		{
			delete _GBufferDepthStencil;
			_GBufferDepthStencil = nullptr;

			delete _GBufferLuminance;
			_GBufferLuminance = nullptr;
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
			}
			return CanRender;
		}
	}
}
