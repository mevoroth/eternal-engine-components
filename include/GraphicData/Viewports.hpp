#ifndef _VIEWPORTS_HPP_
#define _VIEWPORTS_HPP_

#include "GraphicData/StaticCollection.hpp"

namespace Eternal
{
	namespace Graphics
	{
		class Viewport;
	}

	namespace GraphicData
	{
		using namespace Eternal::Graphics;

		enum ViewportKey
		{
			VIEWPORT_FULLSCREEN	= 0,
			VIEWPORT_COUNT
		};

		class Viewports : public StaticCollection<ViewportKey, Viewport, VIEWPORT_COUNT>
		{
		public:
			Viewports();

			virtual void Initialize(_In_ Device& DeviceObj) override;
		};
	}
}

#endif
