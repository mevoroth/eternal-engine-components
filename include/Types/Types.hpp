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
		extern Matrix4x4 operator*(_In_ const Matrix4x4& A, _In_ const Matrix4x4& B);
		extern Matrix4x4& operator*=(_In_ Matrix4x4& A, _In_ const Matrix4x4& B);
		extern Vector4 operator+(_In_ const Vector4& A, _In_ const Vector4& B);
		extern Vector3 operator+(_In_ const Vector3& A, _In_ const Vector3& B);
		extern Vector2 operator+(_In_ const Vector2& A, _In_ const Vector2& B);
		extern Vector4 operator-(_In_ const Vector4& A, _In_ const Vector4& B);
		extern Vector3 operator-(_In_ const Vector3& A, _In_ const Vector3& B);
		extern Vector2 operator-(_In_ const Vector2& A, _In_ const Vector2& B);
		extern Vector4 operator*(_In_ const Vector4& A, _In_ const Vector4& B);
		extern Vector3 operator*(_In_ const Vector3& A, _In_ const Vector3& B);
		extern Vector2 operator*(_In_ const Vector2& A, _In_ const Vector2& B);
		extern Vector4 operator*(_In_ const Matrix4x4& A, _In_ const Vector4& B);
		extern Vector4& operator+=(_In_ Vector4& A, _In_ const Vector4& B);
		extern Vector3& operator+=(_In_ Vector3& A, _In_ const Vector3& B);
		extern Vector2& operator+=(_In_ Vector2& A, _In_ const Vector2& B);
		extern Vector4& operator-=(_In_ Vector4& A, _In_ const Vector4& B);
		extern Vector3& operator-=(_In_ Vector3& A, _In_ const Vector3& B);
		extern Vector2& operator-=(_In_ Vector2& A, _In_ const Vector2& B);
		extern Vector4& operator*=(_In_ Vector4& A, _In_ const Vector4& B);
		extern Vector3& operator*=(_In_ Vector3& A, _In_ const Vector3& B);
		extern Vector2& operator*=(_In_ Vector2& A, _In_ const Vector2& B);
		extern Vector4 operator*(_In_ const Vector4& A, _In_ float B);
		extern Vector4 operator*(_In_ float A, _In_ const Vector4& B);
		extern Vector3 operator*(_In_ const Vector3& A, _In_ float B);
		extern Vector3 operator*(_In_ float A, _In_ const Vector3& B);
		extern Vector2 operator*(_In_ const Vector2& A, _In_ float B);
		extern Vector2 operator*(_In_ float A, _In_ const Vector2& B);

		extern bool operator==(_In_ const Vector4& A, _In_ const Vector4& B);
		extern bool operator==(_In_ const Vector3& A, _In_ const Vector3& B);
		extern bool operator<(_In_ const Vector3& A, _In_ const Vector3& B);
		extern bool operator>(_In_ const Vector3& A, _In_ const Vector3& B);
		extern bool operator<=(_In_ const Vector3& A, _In_ const Vector3& B);
		extern bool operator>=(_In_ const Vector3& A, _In_ const Vector3& B);

		// MATH STUFF: MOVE THIS
		extern void Transpose(_Inout_ Matrix4x4& A);
		extern void Inverse(_Inout_ Matrix4x4& A);
		extern Matrix4x4 NewOrthoLH(_In_ float Top, _In_ float Bottom, _In_ float Left, _In_ float Right, _In_ float Near, _In_ float Far);
		extern Matrix4x4 NewPerpectiveLH(_In_ float XFOV, _In_ float ScreenRatio, _In_ float Near, _In_ float Far);
		extern Matrix4x4 NewLookToLH(_In_ const Vector3& Position, _In_ const Vector3& Direction, _In_ const Vector3& Up);
		extern float SquareLength(_In_ const Vector3& V);
		extern float Length(_In_ const Vector3& V);
		extern Vector3 Normalize(_In_ const Vector3& V);
		extern Vector3 Cross(_In_ const Vector3& A, const Vector3& B);
		extern Vector3 Min(_In_ const Vector3& A, _In_ const Vector3& B);
		extern Vector3 Max(_In_ const Vector3& A, _In_ const Vector3& B);
	}
}

#endif
