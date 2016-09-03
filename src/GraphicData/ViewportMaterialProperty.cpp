#include "GraphicData/ViewportMaterialProperty.hpp"

#include "Graphics/Context.hpp"

using namespace Eternal::GraphicData;

void ViewportMaterialProperty::Apply(_In_ Context& ContextObj)
{
	ContextObj.SetViewport(_Viewport);
}

void ViewportMaterialProperty::Reset(_In_ Context& ContextObj)
{
}

void ViewportMaterialProperty::SetViewport(_In_ Viewport* ViewportObj)
{
	_Viewport = ViewportObj;
}
