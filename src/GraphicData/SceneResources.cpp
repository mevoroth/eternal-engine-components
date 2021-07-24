#include "GraphicData/SceneResources.hpp"
#include "Graphics/GraphicsInclude.hpp"
#include "GraphicData/RenderTargetTexture.hpp"

namespace Eternal
{
	namespace GraphicData
	{
		SceneResources::SceneResources(_In_ GraphicsContext& InContext)
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
						InContext.GetWindow().GetWidth(),
						InContext.GetWindow().GetHeight()
					),
					ResourceMemoryType::RESOURCE_MEMORY_TYPE_GPU_MEMORY,
					TransitionState::TRANSITION_RENDER_TARGET
				),
				RenderTargetTextureFlags::RENDER_TARGET_TEXTURE_FLAGS_GRAPHICS
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
						InContext.GetWindow().GetHeight()
					),
					ResourceMemoryType::RESOURCE_MEMORY_TYPE_GPU_MEMORY,
					TransitionState::TRANSITION_DEPTH_STENCIL_READ | TransitionState::TRANSITION_DEPTH_STENCIL_WRITE
				),
				RenderTargetTextureFlags::RENDER_TARGET_TEXTURE_FLAGS_GRAPHICS
			);
		}

		SceneResources::~SceneResources()
		{
			delete _GBufferEmissive;
			_GBufferEmissive = nullptr;

			delete _GBufferAlbedo;
			_GBufferAlbedo = nullptr;

			delete _GBufferNormals;
			_GBufferNormals = nullptr;

			delete _GBufferRoughnessMetallicSpecular;
			_GBufferRoughnessMetallicSpecular = nullptr;
		}
	}
}
