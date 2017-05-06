#include "GraphicData/RenderTargetCollection.hpp"

#include "Macros/Macros.hpp"
#include "Graphics/RenderTargetFactory.hpp"

using namespace Eternal::GraphicData;

RenderTargetCollection::RenderTargetCollection(_In_ int Width, _In_ int Height, _In_ int RenderTargetsCount, _In_ const Format* Formats, _In_ bool CreateDepth /*= false*/)
{
	ETERNAL_ASSERT(RenderTargetsCount > 0);

	_RenderTargetsCount = RenderTargetsCount;
	_RenderTargets = new RenderTarget*[RenderTargetsCount];

	//for (int RenderTargetIndex = 0; RenderTargetIndex < RenderTargetsCount; ++RenderTargetIndex)
	//{
	//	_RenderTargets[RenderTargetIndex] = CreateRenderTarget(Width, Height, Formats[RenderTargetIndex]);
	//}

	//if (CreateDepth)
	//{
	//	_DepthStencilRenderTarget = CreateDepthStencilRenderTarget(Width, Height);
	//	ETERNAL_ASSERT(_DepthStencilRenderTarget);
	//}
	//else
	//{
	//	_DepthStencilRenderTarget = nullptr;
	//}
}

RenderTargetCollection::RenderTargetCollection(_In_ int Width, _In_ int Height)
	: _RenderTargetsCount(0)
	, _RenderTargets(nullptr)
{
	//_DepthStencilRenderTarget = CreateDepthStencilRenderTarget(Width, Height);
	ETERNAL_ASSERT(_DepthStencilRenderTarget);
}

RenderTargetCollection::~RenderTargetCollection()
{
	ETERNAL_ASSERT(_DepthStencilRenderTarget || _RenderTargets); // Corruption

	if (_DepthStencilRenderTarget)
	{
		delete _DepthStencilRenderTarget;
		_DepthStencilRenderTarget = nullptr;
	}

	if (_RenderTargets)
	{
		for (int RenderTargetIndex = 0; RenderTargetIndex < _RenderTargetsCount; ++RenderTargetIndex)
		{
			delete _RenderTargets[RenderTargetIndex];
			_RenderTargets[RenderTargetIndex] = nullptr;
		}
		delete[] _RenderTargets;
		_RenderTargets = nullptr;
	}
}

RenderTarget** RenderTargetCollection::GetRenderTargets()
{
	return _RenderTargets;
}

int RenderTargetCollection::GetRenderTargetsCount() const
{
	return _RenderTargetsCount;
}

RenderTarget* RenderTargetCollection::GetDepthStencilRenderTarget()
{
	return _DepthStencilRenderTarget;
}

