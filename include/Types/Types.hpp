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
		extern Vector4 NewVector4(float X, float Y, float Z, float W);
		extern Vector3 NewVector3(float X, float Y, float Z);
		extern Vector2 NewVector2(float X, float Y);
		extern Matrix4x4 NewIdentity();
		extern Vector4 operator+(const Vector4& A, const Vector4& B);
		extern Vector3 operator+(const Vector3& A, const Vector3& B);
		extern Vector2 operator+(const Vector2& A, const Vector2& B);
		extern Vector4 operator-(const Vector4& A, const Vector4& B);
		extern Vector3 operator-(const Vector3& A, const Vector3& B);
		extern Vector2 operator-(const Vector2& A, const Vector2& B);
		extern Vector4 operator*(const Vector4& A, const Vector4& B);
		extern Vector3 operator*(const Vector3& A, const Vector3& B);
		extern Vector2 operator*(const Vector2& A, const Vector2& B);
		extern Vector4& operator+=(Vector4& A, const Vector4& B);
		extern Vector3& operator+=(Vector3& A, const Vector3& B);
		extern Vector2& operator+=(Vector2& A, const Vector2& B);
		extern Vector4& operator-=(Vector4& A, const Vector4& B);
		extern Vector3& operator-=(Vector3& A, const Vector3& B);
		extern Vector2& operator-=(Vector2& A, const Vector2& B);
		extern Vector4& operator*=(Vector4& A, const Vector4& B);
		extern Vector3& operator*=(Vector3& A, const Vector3& B);
		extern Vector2& operator*=(Vector2& A, const Vector2& B);
	}
}

#endif
