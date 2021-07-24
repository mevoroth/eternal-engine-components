#pragma once

namespace Eternal
{
	namespace Graphics
	{
		class GraphicsContext;
	}

	namespace GraphicData
	{
		using namespace Eternal::Graphics;

		class RenderTargetTexture;

		class SceneResources
		{
		public:

			SceneResources(_In_ GraphicsContext& InContext);
			~SceneResources();

			RenderTargetTexture& GetGBufferEmissive()
			{
				ETERNAL_ASSERT(_GBufferEmissive);
				return *_GBufferEmissive;
			}

			RenderTargetTexture& GetGBufferAlbedo()
			{
				ETERNAL_ASSERT(_GBufferAlbedo);
				return *_GBufferAlbedo;
			}

			RenderTargetTexture& GetGBufferNormals()
			{
				ETERNAL_ASSERT(_GBufferNormals);
				return *_GBufferNormals;
			}

			RenderTargetTexture& GetGBufferRoughnessMetallicSpecular()
			{
				ETERNAL_ASSERT(_GBufferRoughnessMetallicSpecular);
				return *_GBufferRoughnessMetallicSpecular;
			}

			RenderTargetTexture& GetGBufferDepthStencil()
			{
				ETERNAL_ASSERT(_GBufferDepthStencil);
				return *_GBufferDepthStencil;
			}

		private:

			RenderTargetTexture* _GBufferEmissive					= nullptr;
			RenderTargetTexture* _GBufferAlbedo						= nullptr;
			RenderTargetTexture* _GBufferNormals					= nullptr;
			RenderTargetTexture* _GBufferRoughnessMetallicSpecular	= nullptr;
			RenderTargetTexture* _GBufferDepthStencil				= nullptr;
		};
	}
}
