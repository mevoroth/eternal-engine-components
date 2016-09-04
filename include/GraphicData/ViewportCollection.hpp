#ifndef _VIEWPORT_COLLECTION_HPP_
#define _VIEWPORT_COLLECTION_HPP_

namespace Eternal
{
	namespace Graphics
	{
		class Viewport;
	}

	namespace GraphicData
	{
		using namespace Eternal::Graphics;

		class ViewportCollection
		{
		public:
			enum ViewportKey
			{
				FULLSCREEN = 0,
				VIEWPORT_COUNT
			};

			ViewportCollection();
			~ViewportCollection();

			Viewport* GetViewport(_In_ const ViewportKey& Key);

		private:
			Viewport* _Viewports[VIEWPORT_COUNT];
		};
	}
}

#endif
