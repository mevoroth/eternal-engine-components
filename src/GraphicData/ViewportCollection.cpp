#include "GraphicData/ViewportCollection.hpp"

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
	//_Viewports[FULLSCREEN]	= CreateViewport(0, 0, 1600, 900);
	//_Viewports[MAP_16]		= CreateViewport(0, 0, 16, 16);
	//_Viewports[MAP_32]		= CreateViewport(0, 0, 32, 32);
	//_Viewports[MAP_64]		= CreateViewport(0, 0, 64, 64);
	//_Viewports[MAP_128]		= CreateViewport(0, 0, 128, 128);
	//_Viewports[MAP_256]		= CreateViewport(0, 0, 256, 256);
	//_Viewports[MAP_512]		= CreateViewport(0, 0, 512, 512);
	//_Viewports[MAP_1024]	= CreateViewport(0, 0, 1024, 1024);
	//_Viewports[MAP_2048]	= CreateViewport(0, 0, 2048, 2048);
	//_Viewports[MAP_4096]	= CreateViewport(0, 0, 4096, 4096);
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
