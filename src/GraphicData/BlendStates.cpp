#include "GraphicData/BlendStates.hpp"

#include "Graphics/BlendState.hpp"
#include "Graphics/BlendStateFactory.hpp"

using namespace Eternal::GraphicData;
using namespace Eternal::Graphics;

void BlendStates::Initialize(_In_ Device& DeviceObj)
{
	GetArray()[BLEND_STATE_SOURCE]		= CreateBlendState(BLEND_ONE,		BLEND_ZERO,				BLEND_OP_ADD,	BLEND_ONE,			BLEND_ZERO,				BLEND_OP_ADD,	BLEND_CHANNEL_ALL);
	GetArray()[BLEND_STATE_ALPHA]		= CreateBlendState(BLEND_SRC_ALPHA,	BLEND_INV_SRC_ALPHA,	BLEND_OP_ADD,	BLEND_SRC_ALPHA,	BLEND_INV_SRC_ALPHA,	BLEND_OP_ADD,	BLEND_CHANNEL_ALL);
	GetArray()[BLEND_STATE_ADDITIVE]	= CreateBlendState(BLEND_SRC_ALPHA,	BLEND_ONE,				BLEND_OP_ADD,	BLEND_SRC_ALPHA,	BLEND_ONE,				BLEND_OP_ADD,	BLEND_CHANNEL_ALL);
}