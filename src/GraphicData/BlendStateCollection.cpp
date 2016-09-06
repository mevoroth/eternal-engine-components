#include "GraphicData/BlendStateCollection.hpp"

#include "Macros/Macros.hpp"
#include "Graphics/BlendStateFactory.hpp"

#include "Graphics/BlendState.hpp"

using namespace Eternal::GraphicData;

BlendStateCollection::BlendStateCollection()
{
#ifdef ETERNAL_DEBUG
	static bool Initialized = false;
	ETERNAL_ASSERT(!Initialized);
	Initialized = true;
#endif

	for (int BlendStateIndex = 0; BlendStateIndex < BLENDSTATE_COUNT; ++BlendStateIndex)
	{
		_BlendStates[BlendStateIndex] = nullptr;
	}
	_BlendStates[SOURCE]	= CreateBlendState(BlendState::ONE, BlendState::ZERO, BlendState::OP_ADD, BlendState::ONE, BlendState::ZERO, BlendState::OP_ADD);
	_BlendStates[ALPHA]		= CreateBlendState(BlendState::SRC_ALPHA, BlendState::INV_SRC_ALPHA, BlendState::OP_ADD, BlendState::INV_SRC_ALPHA, BlendState::INV_SRC_ALPHA, BlendState::OP_ADD);
	_BlendStates[ADDITIVE]	= CreateBlendState(BlendState::SRC_ALPHA, BlendState::ONE, BlendState::OP_ADD, BlendState::SRC_ALPHA, BlendState::ONE, BlendState::OP_ADD);
}

BlendStateCollection::~BlendStateCollection()
{
	for (int BlendStateIndex = 0; BlendStateIndex < BLENDSTATE_COUNT; ++BlendStateIndex)
	{
		delete _BlendStates[BlendStateIndex];
		_BlendStates[BlendStateIndex] = nullptr;
	}
}

BlendState* BlendStateCollection::GetBlendState(_In_ const BlendStateKey& Key)
{
	ETERNAL_ASSERT(Key < BLENDSTATE_COUNT);
	ETERNAL_ASSERT(_BlendStates[Key]);
	return _BlendStates[Key];
}
