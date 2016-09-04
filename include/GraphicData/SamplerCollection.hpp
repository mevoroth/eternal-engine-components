#ifndef _SAMPLER_COLLECTION_HPP_
#define _SAMPLER_COLLECTION_HPP_

namespace Eternal
{
	namespace Graphics
	{
		class Sampler;
	}

	namespace GraphicData
	{
		using namespace Eternal::Graphics;

		class SamplerCollection
		{
		public:
			enum SamplerKey
			{
				BILINEAR = 0,
				SAMPLER_COUNT
			};

			SamplerCollection();
			~SamplerCollection();

			Sampler* GetSampler(_In_ const SamplerKey& Key);

		private:
			Sampler* _Samplers[SAMPLER_COUNT];
		};
	}
}

#endif
