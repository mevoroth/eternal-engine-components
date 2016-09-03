#include "GraphicData/SamplerMaterialProperty.hpp"

#include "Graphics/Context.hpp"

using namespace Eternal::GraphicData;
using namespace Eternal::Graphics;

void SamplerMaterialProperty::Apply(_In_ Context& ContextObj)
{
	ContextObj.BindSampler<Context::PIXEL>(0, _Sampler);
}

void SamplerMaterialProperty::Reset(_In_ Context& ContextObj)
{
	ContextObj.UnbindSampler<Context::PIXEL>(0);
}

void SamplerMaterialProperty::SetSampler(_In_ Sampler* SamplerObj)
{
	_Sampler = SamplerObj;
}
