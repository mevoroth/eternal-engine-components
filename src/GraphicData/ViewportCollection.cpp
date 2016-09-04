#include "GraphicData/ViewportCollection.hpp"

#include "Macros/Macros.hpp"
#include "Graphics/ViewportFactory.hpp"

using namespace Eternal::GraphicData;

ViewportCollection::ViewportCollection()
{
#ifdef ETERNAL_DEBUG
	static bool Initialized = false;
	ETERNAL_ASSERT(!Initialized);
	Initialized = true;
#endif

	for (int ViewportIndex = 0; ViewportIndex < VIEWPORT_COUNT; ++ViewportIndex)
	{
		_Viewports[ViewportIndex] = nullptr;
	}
	_Viewports[FULLSCREEN] = CreateViewport(0, 0, 1600, 900);
}

ViewportCollection::~ViewportCollection()
{
	for (int ViewportIndex = 0; ViewportIndex < VIEWPORT_COUNT; ++ViewportIndex)
	{
		delete _Viewports[ViewportIndex];
		_Viewports[ViewportIndex] = nullptr;
	}
}

Viewport* ViewportCollection::GetViewport(_In_ const ViewportKey& Key)
{
	ETERNAL_ASSERT(Key < VIEWPORT_COUNT);
	ETERNAL_ASSERT(_Viewports[Key]);
	return _Viewports[Key];
}
