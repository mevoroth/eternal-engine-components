#ifndef _SAMPLER_MATERIAL_PROPERTY_HPP_
#define _SAMPLER_MATERIAL_PROPERTY_HPP_

#include "GraphicData/MaterialProperty.hpp"

namespace Eternal
{
	namespace Graphics
	{
		class Sampler;
	}

	namespace GraphicData
	{
		using namespace Eternal::Graphics;

		class SamplerMaterialProperty : public MaterialProperty
		{
		public:
			virtual void Apply(_In_ Context& ContextObj) override;
			virtual void Reset(_In_ Context& ContextObj) override;

			void SetSampler(_In_ Sampler* SamplerObj);

		private:
			Sampler* _Sampler = nullptr;
		};
	}
}

#endif
