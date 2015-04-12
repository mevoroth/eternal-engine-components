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

Matrix4x4 Eternal::Types::NewIdentity()
{
	return XMMatrixIdentity();
}

Vector4 operator+(const Vector4& A, const Vector4& B)
{
	return XMVectorAdd(A, B);
}
Vector3 operator+(const Vector3& A, const Vector3& B)
{
	return XMFLOAT3(A.x + B.x, A.y + B.y, A.z + B.z);
}
Vector2 operator+(const Vector2& A, const Vector2& B)
{
	return XMFLOAT2(A.x + B.x, A.y + B.y);
}
Vector4 operator-(const Vector4& A, const Vector4& B)
{
	return XMVectorSubtract(A, B);
}
Vector3 operator-(const Vector3& A, const Vector3& B)
{
	return XMFLOAT3(A.x - B.x, A.y - B.y, A.z - B.z);
}
Vector2 operator-(const Vector2& A, const Vector2& B)
{
	return XMFLOAT2(A.x - B.x, A.y - B.y);
}
Vector4 operator*(const Vector4& A, const Vector4& B)
{
	return XMVectorMultiply(A, B);
}
Vector3 operator*(const Vector3& A, const Vector3& B)
{
	return XMFLOAT3(A.x * B.x, A.y * B.y, A.z * B.z);
}
Vector2 operator*(const Vector2& A, const Vector2& B)
{
	return XMFLOAT2(A.x * B.x, A.y * B.y);
}
Vector4& operator+=(Vector4& A, const Vector4& B)
{
	A = XMVectorAdd(A, B);
	return A;
}
Vector3& operator+=(Vector3& A, const Vector3& B)
{
	A = XMFLOAT3(A.x + B.x, A.y + B.y, A.z + B.z);
	return A;

}
Vector2& operator+=(Vector2& A, const Vector2& B)
{
	A = XMFLOAT2(A.x + B.x, A.y + B.y);
	return A;
}
Vector4& operator-=(Vector4& A, const Vector4& B)
{
	A = XMVectorSubtract(A, B);
	return A;
}
Vector3& operator-=(Vector3& A, const Vector3& B)
{
	A = XMFLOAT3(A.x - B.x, A.y - B.y, A.z - B.z);
	return A;
}
Vector2& operator-=(Vector2& A, const Vector2& B)
{
	A = XMFLOAT2(A.x - B.x, A.y - B.y);
	return A;
}
Vector4& operator*=(Vector4& A, const Vector4& B)
{
	A = XMVectorMultiply(A, B);
	return A;
}
Vector3& operator*=(Vector3& A, const Vector3& B)
{
	A = XMFLOAT3(A.x * B.x, A.y * B.y, A.z * B.z);
	return A;
}
Vector2& operator*=(Vector2& A, const Vector2& B)
{
	A = XMFLOAT2(A.x * B.x, A.y * B.y);
	return A;
}
