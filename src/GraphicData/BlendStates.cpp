#include "GraphicData/BlendStates.hpp"

#include "Graphics/BlendState.hpp"
#include "Graphics/BlendStateFactory.hpp"

using namespace Eternal::GraphicData;
using namespace Eternal::Graphics;

void BlendStates::Initialize(_In_ Device& DeviceObj)
{
	GetArray()[BLEND_STATE_SOURCE]		= CreateBlendState(Blend::BLEND_ONE,		Blend::BLEND_ZERO,				BlendOp::BLEND_OP_ADD,	Blend::BLEND_ONE,		Blend::BLEND_ZERO,			BlendOp::BLEND_OP_ADD,	BlendChannel::BLEND_CHANNEL_ALL);
	GetArray()[BLEND_STATE_ALPHA]		= CreateBlendState(Blend::BLEND_SRC_ALPHA,	Blend::BLEND_INV_SRC_ALPHA,		BlendOp::BLEND_OP_ADD,	Blend::BLEND_SRC_ALPHA,	Blend::BLEND_INV_SRC_ALPHA,	BlendOp::BLEND_OP_ADD,	BlendChannel::BLEND_CHANNEL_ALL);
	GetArray()[BLEND_STATE_ADDITIVE]	= CreateBlendState(Blend::BLEND_SRC_ALPHA,	Blend::BLEND_ONE,				BlendOp::BLEND_OP_ADD,	Blend::BLEND_SRC_ALPHA,	Blend::BLEND_ONE,			BlendOp::BLEND_OP_ADD,	BlendChannel::BLEND_CHANNEL_ALL);
}