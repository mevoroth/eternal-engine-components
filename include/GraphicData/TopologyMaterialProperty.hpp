#ifndef _TOPOLOGY_MATERIAL_PROPERTY_HPP_
#define _TOPOLOGY_MATERIAL_PROPERTY_HPP_

#include "GraphicData/MaterialProperty.hpp"

namespace Eternal
{
	namespace GraphicData
	{
		class TopologyMaterialProperty : public MaterialProperty
		{
		public:
			virtual void Apply(_In_ Context& ContextObj) override;
			virtual void Reset(_In_ Context& ContextObj) override;
		};
	}
}

#endif
