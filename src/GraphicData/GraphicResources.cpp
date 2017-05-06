#include "GraphicData/GraphicResources.hpp"

#include "Macros/Macros.hpp"
#include "GraphicData/StaticCollection.hpp"
#include "GraphicData/CommandQueues.hpp"
#include "GraphicData/StaticSamplers.hpp"
#include "GraphicData/Viewports.hpp"

using namespace Eternal::GraphicData;

GraphicResources::GraphicResources()
{
	_Collections.CommandQueuesResources		= new CommandQueues();
	_Collections.StaticSamplersResources	= new StaticSamplers();
	_Collections.ViewportsResources			= new Viewports();
}

GraphicResources::~GraphicResources()
{
	for (uint32_t ResourceIndex = 0; ResourceIndex < ETERNAL_ARRAYSIZE(_Collections.Initializers); ++ResourceIndex)
	{
		delete _Collections.Initializers[ResourceIndex];
		_Collections.Initializers[ResourceIndex] = nullptr;
	}
}

void GraphicResources::Initialize(_In_ Device& DeviceObj)
{
	for (uint32_t ResourceIndex = 0; ResourceIndex < ETERNAL_ARRAYSIZE(_Collections.Initializers); ++ResourceIndex)
	{
		_Collections.Initializers[ResourceIndex]->Initialize(DeviceObj);
	}
}
