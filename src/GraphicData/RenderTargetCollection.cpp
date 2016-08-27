#include "GraphicData/RenderTargetCollection.hpp"

#include "Macros/Macros.hpp"
#include "Graphics/RenderTargetFactory.hpp"

using namespace Eternal::GraphicData;

RenderTargetCollection::RenderTargetCollection(_In_ int Width, _In_ int Height, _In_ int RenderTargetsCount, _In_ const Format* Formats)
{
	ETERNAL_ASSERT(RenderTargetsCount > 0);

	_RenderTargetsCount = RenderTargetsCount;
	_RenderTargets = new RenderTarget*[RenderTargetsCount];

	for (int RenderTargetIndex = 0; RenderTargetIndex < RenderTargetsCount; ++RenderTargetIndex)
	{
		_RenderTargets[RenderTargetIndex] = CreateRenderTarget(Width, Height, Formats[RenderTargetIndex]);
	}
}

RenderTargetCollection::~RenderTargetCollection()
{
	for (int RenderTargetIndex = 0; RenderTargetIndex < _RenderTargetsCount; ++RenderTargetIndex)
	{
		delete _RenderTargets[RenderTargetIndex];
		_RenderTargets[RenderTargetIndex] = nullptr;
	}
	delete[] _RenderTargets;
	_RenderTargets = nullptr;
}

RenderTarget** RenderTargetCollection::GetRenderTargets()
{
	return _RenderTargets;
}

int RenderTargetCollection::GetRenderTargetsCount() const
{
	return _RenderTargetsCount;
}
