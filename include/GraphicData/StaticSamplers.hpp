#ifndef _STATIC_SAMPLERS_HPP_
#define _STATIC_SAMPLERS_HPP_

#include "GraphicData/StaticCollection.hpp"

namespace Eternal
{
	namespace Graphics
	{
		class Device;
		class Sampler;
	}

	namespace GraphicData
	{
		using namespace Eternal::Graphics;

		enum SamplerKey
		{
			SAMPLER_BILINEAR = 0,
			SAMPLERS_COUNT
		};

		class StaticSamplers : public StaticCollection<SamplerKey, Sampler, SAMPLERS_COUNT>
		{
		public:
			StaticSamplers();
			virtual void Initialize(_In_ Device& DeviceObj) override;
		};
	}
}

#endif
