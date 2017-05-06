#include "GraphicData/StaticSamplers.hpp"

#include "NextGenGraphics/SamplerFactory.hpp"
#include "Graphics/Sampler.hpp"

using namespace Eternal::GraphicData;
using namespace Eternal::Graphics;

StaticSamplers::StaticSamplers()
	: StaticCollection<SamplerKey, Sampler, SAMPLERS_COUNT>()
{
}

void StaticSamplers::Initialize(_In_ Device& DeviceObj)
{
	GetArray()[BILINEAR] = CreateSampler(DeviceObj, *(DescriptorHeap*)nullptr, true, true, false, false, Sampler::WRAP, Sampler::WRAP, Sampler::WRAP);
}
