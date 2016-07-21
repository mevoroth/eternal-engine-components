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
		extern Vector4 operator*(const Matrix4x4& A, const Vector4& B);
		extern Vector4& operator+=(Vector4& A, const Vector4& B);
		extern Vector3& operator+=(Vector3& A, const Vector3& B);
		extern Vector2& operator+=(Vector2& A, const Vector2& B);
		extern Vector4& operator-=(Vector4& A, const Vector4& B);
		extern Vector3& operator-=(Vector3& A, const Vector3& B);
		extern Vector2& operator-=(Vector2& A, const Vector2& B);
		extern Vector4& operator*=(Vector4& A, const Vector4& B);
		extern Vector3& operator*=(Vector3& A, const Vector3& B);
		extern Vector2& operator*=(Vector2& A, const Vector2& B);
		extern Vector4 operator*(const Vector4& A, float B);
		extern Vector4 operator*(float A, const Vector4& B);
		extern Vector3 operator*(const Vector3& A, float B);
		extern Vector3 operator*(float A, const Vector3& B);
		extern Vector2 operator*(const Vector2& A, float B);
		extern Vector2 operator*(float A, const Vector2& B);

		extern bool operator==(const Vector4& A, const Vector4& B);

		// MATH STUFF: MOVE THIS
		extern Matrix4x4 NewOrthoLH(float Top, float Bottom, float Left, float Right, float Near, float Far);
		extern Matrix4x4 NewLookToLH(const Vector3& Position, const Vector3& Direction, const Vector3& Up);
		extern float SquareLength(const Vector3& V);
		extern float Length(const Vector3& V);
		extern Vector3 Normalize(const Vector3& V);
		extern Vector3 Cross(const Vector3& A, const Vector3& B);
	}
}

#endif
