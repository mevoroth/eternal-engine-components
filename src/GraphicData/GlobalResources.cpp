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

		constexpr uint32_t GlobalResources::TemporaryLuminanceTexturesCount;

		GlobalResources::GlobalResources(_In_ GraphicsContext& InContext)
			: _ViewConstantBuffer(InContext, "ViewConstantBuffer")
		{
			for (uint32_t TemporaryLuminanceTextureIndex = 0; TemporaryLuminanceTextureIndex < TemporaryLuminanceTexturesCount; ++TemporaryLuminanceTextureIndex)
			{
				char GBufferLuminanceName[256];
				sprintf_s(GBufferLuminanceName, "GBufferLuminance%d", TemporaryLuminanceTextureIndex);

				_GBufferLuminance[TemporaryLuminanceTextureIndex] = new RenderTargetTexture(
					InContext,
					TextureResourceCreateInformation(
						InContext.GetDevice(),
						GBufferLuminanceName,
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
			}

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

			for (uint32_t TemporaryLuminanceTextureIndex = 0; TemporaryLuminanceTextureIndex < TemporaryLuminanceTexturesCount; ++TemporaryLuminanceTextureIndex)
			{
				delete _GBufferLuminance[TemporaryLuminanceTextureIndex];
				_GBufferLuminance[TemporaryLuminanceTextureIndex] = nullptr;
			}
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

			_CurrentLuminanceIndex = 0;

			return CanRender;
		}

		void GlobalResources::SwapIntermediateLuminanceTexture()
		{
			_CurrentLuminanceIndex = (_CurrentLuminanceIndex + 1) % TemporaryLuminanceTexturesCount;
		}
	}
}
