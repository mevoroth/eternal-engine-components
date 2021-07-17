#pragma once

#include "Types/Types.hpp"

namespace Eternal
{
	namespace GraphicData
	{
		using namespace Eternal::Types;

		struct PositionColorVertex
		{
			Vector4 Position	= Vector4::ZeroPosition;
			PackedColor Color;
		};

		struct PositionNormalTangentBinormalUVVertex
		{
			Vector4 Position	= Vector4::ZeroPosition;
			Vector3 Normal		= Vector3::Up;		// Up
			Vector3 Tangent		= Vector3::Forward;	// Fw
			Vector3 Binormal	= Vector3::Right;	// R
			Vector2 UV			= Vector2::Zero;
		};

		struct PositionUVVertex
		{
			Vector4 Position;
			Vector2 UV;
		};
	}
}
