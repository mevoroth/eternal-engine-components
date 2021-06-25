#include "GraphicData/StaticSamplers.hpp"

#include "NextGenGraphics/SamplerFactory.hpp"
//#include "Graphics_deprecated/Sampler.hpp"

using namespace Eternal::GraphicData;
using namespace Eternal::Graphics;

StaticSamplers::StaticSamplers()
	: StaticCollection<SamplerKey, Sampler, SAMPLER_COUNT>()
{
}

void StaticSamplers::Initialize(_In_ Device& DeviceObj)
{
	//GetArray()[SAMPLER_BILINEAR] = CreateStaticSampler(DeviceObj, 0, true, true, false, false, ADDRESS_MODE_WRAP, ADDRESS_MODE_WRAP, ADDRESS_MODE_WRAP);
}
