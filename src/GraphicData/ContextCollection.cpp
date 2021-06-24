#include "GraphicData/ContextCollection.hpp"

//#include "Graphics/Renderer.hpp"
//#include "Graphics/Context.hpp"
#include "Parallel/AtomicS32Factory.hpp"
#include "Parallel/AtomicS32.hpp"

using namespace Eternal::GraphicData;

ContextCollection::ContextCollection(_In_ Renderer& RendererObj,_In_ int ContextCount)
	: _ContextCount(ContextCount)
{
	//ETERNAL_ASSERT(_ContextCount > 0);
	//_ContextReservation = new AtomicS32*[_ContextCount];
	//_Contexts = new Context*[_ContextCount];
	//for (int ContextIndex = 0; ContextIndex < _ContextCount; ++ContextIndex)
	//{
	//	_Contexts[ContextIndex] = RendererObj.CreateDeferredContext();
	//	_ContextReservation[ContextIndex] = CreateAtomicS32();
	//}
}

ContextCollection::~ContextCollection()
{
	//for (int ContextIndex = 0; ContextIndex < _ContextCount; ++ContextIndex)
	//{
	//	delete _Contexts[ContextIndex];
	//	_Contexts[ContextIndex] = nullptr;
	//}

	delete[] _Contexts;
	_Contexts = nullptr;
}

Context& ContextCollection::Get()
{
	for (int ContextIndex = 0; ContextIndex < _ContextCount; ++ContextIndex)
	{
		if (_ContextReservation[ContextIndex]->CompareAndSwap(0, 1))
			return *_Contexts[ContextIndex];
	}

	ETERNAL_BREAK();
	return *(Context*)nullptr;
}

void ContextCollection::Release(_In_ Context& ContextObj)
{
	for (int ContextIndex = 0; ContextIndex < _ContextCount; ++ContextIndex)
	{
		if (_Contexts[ContextIndex] == &ContextObj)
		{
			ETERNAL_ASSERT(_ContextReservation[ContextIndex]->Load() == 1);
			_ContextReservation[ContextIndex]->Sub();
		}
	}
}

void ContextCollection::Flush(_In_ Context& MainContext)
{
//#ifdef ETERNAL_DEBUG
//	ETERNAL_ASSERT(!MainContext.IsDeferred());
//	for (int ContextIndex = 0; ContextIndex < _ContextCount; ++ContextIndex)
//	{
//		bool Reserve = _ContextReservation[ContextIndex]->CompareAndSwap(0, 1);
//		ETERNAL_ASSERT(Reserve);
//	}
//#endif
//
//	for (int ContextIndex = 0; ContextIndex < _ContextCount; ++ContextIndex)
//	{
//		_Contexts[ContextIndex]->PrepareFlush(MainContext);
//	}
//
//#ifdef ETERNAL_DEBUG
//	for (int ContextIndex = 0; ContextIndex < _ContextCount; ++ContextIndex)
//	{
//		_ContextReservation[ContextIndex]->Sub();
//		ETERNAL_ASSERT(_ContextReservation[ContextIndex]->Load() == 0);
//	}
//#endif
//
//	MainContext.Flush();
}
