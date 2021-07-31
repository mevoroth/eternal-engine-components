#pragma once

#include <vector>

namespace Eternal
{
	namespace Graphics
	{
		class GraphicsContext;
		class Resource;
		class View;
		struct TextureResourceCreateInformation;
	}

	namespace GraphicData
	{
		using namespace std;
		using namespace Eternal::Graphics;

		enum class RenderTargetTextureFlags
		{
			RENDER_TARGET_TEXTURE_FLAGS_SHADER_RESOURCE_VIEW				= 0x1,
			RENDER_TARGET_TEXTURE_FLAGS_RENDER_TARGET_DEPTH_STENCIL_VIEW	= 0x2,
			RENDER_TARGET_TEXTURE_FLAGS_UNORDERED_ACCESS_VIEW				= 0x4,

			RENDER_TARGET_TEXTURE_FLAGS_GRAPHICS							= (RENDER_TARGET_TEXTURE_FLAGS_SHADER_RESOURCE_VIEW | RENDER_TARGET_TEXTURE_FLAGS_RENDER_TARGET_DEPTH_STENCIL_VIEW),
			RENDER_TARGET_TEXTURE_FLAGS_COMPUTE								= (RENDER_TARGET_TEXTURE_FLAGS_SHADER_RESOURCE_VIEW | RENDER_TARGET_TEXTURE_FLAGS_UNORDERED_ACCESS_VIEW),
			RENDER_TARGET_TEXTURE_FLAGS_ALL									= (RENDER_TARGET_TEXTURE_FLAGS_SHADER_RESOURCE_VIEW | RENDER_TARGET_TEXTURE_FLAGS_RENDER_TARGET_DEPTH_STENCIL_VIEW | RENDER_TARGET_TEXTURE_FLAGS_UNORDERED_ACCESS_VIEW)
		};

		RenderTargetTextureFlags operator&(_In_ const RenderTargetTextureFlags& InRenderTargetTextureFlagsLeft, _In_ const RenderTargetTextureFlags& InRenderTargetTextureFlagsRight);

		class RenderTargetTexture
		{
		public:

			RenderTargetTexture(_In_ GraphicsContext& InContext, _In_ const TextureResourceCreateInformation& InTextureResourceCreateInformation, _In_ const RenderTargetTextureFlags& InFlags);
			~RenderTargetTexture();

			Resource&	GetTexture() { return *_Texture; }
			View*		GetShaderResourceView() { return _ShaderResourceView; }
			View*		GetRenderTargetDepthStencilView() { return _RenderTargetDepthStencilView; }
			View*		GetUnorderedAccessView() { return _UnorderedAccessView; }

		private:
			Resource*	_Texture						= nullptr;
			View*		_ShaderResourceView				= nullptr;
			View*		_RenderTargetDepthStencilView	= nullptr;
			View*		_UnorderedAccessView			= nullptr;
		};
	}
}
