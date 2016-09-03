#include "GraphicData/TopologyMaterialProperty.hpp"

#include "Graphics/Context.hpp"

using namespace Eternal::Graphics;
using namespace Eternal::GraphicData;

void TopologyMaterialProperty::Apply(_In_ Context& ContextObj)
{
	ContextObj.SetTopology(Context::TRIANGLELIST);
}

void TopologyMaterialProperty::Reset(_In_ Context& ContextObj)
{
}
