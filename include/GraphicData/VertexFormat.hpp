#ifndef _VERTEX_FORMAT_HPP_
#define _VERTEX_FORMAT_HPP_

#include "Types/Types.hpp"

namespace Eternal
{
	namespace GraphicData
	{
		using namespace Eternal::Types;

		class PosColorVertex
		{
		public:
			Vector4 Pos;
			uint32_t Color;
		};

		class PosUVNormalTangentBinormalVertex
		{
		public:
			Vector4 Pos;
			Vector4 Normal;		// Up
			Vector4 Tangent;	// Fw
			Vector4 Binormal;	// R
			Vector2 UV;
		};

		class PosUVVertex
		{
		public:
			Vector4 Pos;
			Vector2 UV;
		};
	}
}

#endif
