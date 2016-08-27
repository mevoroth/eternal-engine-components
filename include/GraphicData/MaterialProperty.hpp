#ifndef _MATERIAL_PROPERTY_HPP_
#define _MATERIAL_PROPERTY_HPP_

namespace Eternal
{
	namespace Graphics
	{
		class Context;
	}

	namespace GraphicData
	{
		using namespace Eternal::Graphics;

		class MaterialProperty
		{
		public:
			virtual void Apply(_In_ Context& ContextObj) = 0;
			virtual void Reset(_In_ Context& ContextObj) = 0;
		};
	}
}

#endif
