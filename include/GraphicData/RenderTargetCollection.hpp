#ifndef _RENDER_TARGET_COLLECTION_HPP_
#define _RENDER_TARGET_COLLECTION_HPP_

namespace Eternal
{
	namespace Graphics
	{
		enum Format;
		class RenderTarget;
	}

	namespace GraphicData
	{
		using namespace Eternal::Graphics;

		class RenderTargetCollection
		{
		public:
			/**
			 * Rendertargets + Depth
			 */
			RenderTargetCollection(_In_ int Width, _In_ int Height, _In_ int RenderTargetsCount, _In_ const Format* Formats, _In_ bool CreateDepth = false);
			/**
			 * Only Depth
			 */
			RenderTargetCollection(_In_ int Width, _In_ int Height);
			virtual ~RenderTargetCollection();

			RenderTarget** GetRenderTargets();
			int GetRenderTargetsCount() const;

			RenderTarget* GetDepthStencilRenderTarget();

		private:
			RenderTarget* _DepthStencilRenderTarget = nullptr;
			RenderTarget** _RenderTargets = nullptr;
			int _RenderTargetsCount = 0;
		};
	}
}

#endif
