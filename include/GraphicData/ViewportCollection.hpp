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
				MAP_16,
				MAP_32,
				MAP_64,
				MAP_128,
				MAP_256,
				MAP_512,
				MAP_1024,
				MAP_2048,
				MAP_4096,
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
