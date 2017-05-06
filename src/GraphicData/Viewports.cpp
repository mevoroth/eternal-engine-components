#include "GraphicData/Viewports.hpp"

#include "Graphics/ViewportFactory.hpp"

using namespace Eternal::GraphicData;

Viewports::Viewports()
	: StaticCollection<ViewportKey, Viewport, VIEWPORT_COUNT>()
{
}

void Viewports::Initialize(_In_ Device& DeviceObj)
{
	GetArray()[FULLSCREEN] = CreateViewport(0, 0, 1280, 720);
}
