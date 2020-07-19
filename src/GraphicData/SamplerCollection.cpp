#include "GraphicData/SamplerCollection.hpp"

#include "Graphics/SamplerFactory.hpp"

using namespace Eternal::GraphicData;

SamplerCollection::SamplerCollection()
{
#ifdef ETERNAL_DEBUG
	static bool Initialized = false;
	ETERNAL_ASSERT(!Initialized);
	Initialized = true;
#endif

	for (int SamplerIndex = 0; SamplerIndex < SAMPLER_COUNT; ++SamplerIndex)
	{
		_Samplers[SamplerIndex] = nullptr;
	}
	//_Samplers[BILINEAR] = CreateSampler(true, true, false, false, Sampler::WRAP, Sampler::WRAP, Sampler::WRAP);
}

SamplerCollection::~SamplerCollection()
{
	for (int SamplerIndex = 0; SamplerIndex < SAMPLER_COUNT; ++SamplerIndex)
	{
		delete _Samplers[SamplerIndex];
		_Samplers[SamplerIndex] = nullptr;
	}
}

Sampler* SamplerCollection::GetSampler(_In_ const SamplerKey& Key)
{
	ETERNAL_ASSERT(Key < SAMPLER_COUNT);
	ETERNAL_ASSERT(_Samplers[Key]);
	return _Samplers[Key];
}
