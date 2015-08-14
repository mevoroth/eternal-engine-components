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
		extern Matrix4x4 NewIdentity();
		extern Matrix4x4 operator*(const Matrix4x4& A, const Matrix4x4& B);
		extern Matrix4x4& operator*=(Matrix4x4& A, const Matrix4x4& B);
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
