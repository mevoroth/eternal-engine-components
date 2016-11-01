#include "GraphicData/GraphicTaskConfigCollection.hpp"

#include "Macros/Macros.hpp"
#include "GraphicData/BlendStateCollection.hpp"
#include "GraphicData/ViewportCollection.hpp"

using namespace Eternal::GraphicData;

GraphicTaskConfigCollection::GraphicTaskConfigCollection()
{
#ifdef ETERNAL_DEBUG
	static bool Initialized = false;
	ETERNAL_ASSERT(!Initialized);
	Initialized = true;
#endif

	{
		GraphicTaskConfig& Config = _GraphicTaskConfigs[OPAQUE_TASK];

		Config.BlendConfig		= BlendStateCollection::SOURCE;
		Config.ViewportConfig	= ViewportCollection::FULLSCREEN;
		Config.PS				= "Opaque";
		Config.PSFile			= "opaque.ps.hlsl";
	}

	{
		GraphicTaskConfig& Config = _GraphicTaskConfigs[SHADOW_TASK];

		Config.BlendConfig		= BlendStateCollection::SOURCE;
		Config.ViewportConfig	= ViewportCollection::MAP_2048;
		Config.PS				= "Opaque";
		Config.PSFile			= "opaque.ps.hlsl";
		{
			Config.Defines.push_back("USE_DEPTH");
			Config.Defines.push_back("1");
		}
	}
}

const GraphicTaskConfig& GraphicTaskConfigCollection::GetGraphicTaskConfig(_In_ const GraphicTaskConfigKey& Key)
{
	ETERNAL_ASSERT(Key < GRAPHICTASKCONFIG_COUNT);
	return _GraphicTaskConfigs[Key];
}
