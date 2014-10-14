#include "Types/Types.hpp"

using namespace Eternal::Types;

Vector4 Eternal::Types::NewVector4(float x, float y, float z, float w)
{
	return XMVectorSet(x, y, z, w);
}

Vector3 Eternal::Types::NewVector3(float x, float y, float z)
{
	return XMFLOAT3(x, y, z);
}

Vector2 Eternal::Types::NewVector2(float x, float y)
{
	return XMFLOAT2(x, y);
}
