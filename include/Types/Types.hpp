#ifndef _TYPES_HPP_
#define _TYPES_HPP_

#include "ComponentsSettings.hpp"
#ifdef ETERNAL_USE_DXMATH_TYPES
#include "DXMathTypes.hpp"
#endif

namespace Eternal
{
	namespace Types
	{
		extern Vector4 NewVector4(float x, float y, float z, float w);
		extern Vector3 NewVector3(float x, float y, float z);
		extern Vector2 NewVector2(float x, float y);
	}
}

#endif
