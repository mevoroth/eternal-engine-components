#pragma once

#include "ComponentsSettings.hpp"
#ifdef ETERNAL_USE_DXMATH_TYPES
#include "DXMathTypes.hpp"
#endif

namespace Eternal
{
	namespace Types
	{
		typedef unsigned long long	u64;
		typedef long long			s64;
		typedef unsigned int		u32;
		typedef int					s32;
		typedef char				s8;
		typedef unsigned char		u8;

		struct Color8888
		{
			uint8_t R = 0;
			uint8_t G = 0;
			uint8_t B = 0;
			uint8_t A = 0;
		};
		union PackedColor
		{
			Color8888 Color;
			uint32_t Packed;
		};

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
		extern Vector2 operator/(_In_ const Vector2& A, _In_ float B);
		extern Vector4 operator-(_In_ const Vector4& InVector);
		extern Vector3 operator-(_In_ const Vector3& InVector);
		extern Vector2 operator-(_In_ const Vector2& InVector);

		extern bool operator==(_In_ const Vector4& A, _In_ const Vector4& B);
		extern bool operator==(_In_ const Vector3& A, _In_ const Vector3& B);
		extern Vector3 operator<(_In_ const Vector3& A, _In_ const Vector3& B);
		extern Vector3 operator>(_In_ const Vector3& A, _In_ const Vector3& B);
		extern Vector3 operator<=(_In_ const Vector3& A, _In_ const Vector3& B);
		extern Vector3 operator>=(_In_ const Vector3& A, _In_ const Vector3& B);
		extern Vector2 operator<(_In_ const Vector2& A, _In_ const Vector2& B);
		extern Vector2 operator>=(_In_ const Vector2& A, _In_ const Vector2& B);

		extern Vector4 Min(_In_ const Vector4& A, _In_ const Vector4& B);
		extern Vector3 Min(_In_ const Vector3& A, _In_ const Vector3& B);
		extern Vector2 Min(_In_ const Vector2& A, _In_ const Vector2& B);
		extern Vector4 Max(_In_ const Vector4& A, _In_ const Vector4& B);
		extern Vector3 Max(_In_ const Vector3& A, _In_ const Vector3& B);
		extern Vector2 Max(_In_ const Vector2& A, _In_ const Vector2& B);

		// MATH STUFF: MOVE THIS
		extern void Transpose(_Inout_ Matrix4x4& A);
		extern void Inverse(_Inout_ Matrix4x4& A);
		extern Matrix4x4 NewOrthoLH(_In_ float Top, _In_ float Bottom, _In_ float Left, _In_ float Right, _In_ float Near, _In_ float Far);
		extern Matrix4x4 NewPerspectiveLH(_In_ float YFOV, _In_ float ScreenRatio, _In_ float Near, _In_ float Far);
		extern Matrix4x4 NewReversePerspectiveLH(_In_ float YFOV, _In_ float ScreenRatio, _In_ float Near, _In_ float Far);
		extern Matrix4x4 NewLookToLH(_In_ const Vector3& Position, _In_ const Vector3& Direction, _In_ const Vector3& Up);
		extern float SquareLength(_In_ const Vector3& V);
		extern float Length(_In_ const Vector3& V);
		extern Vector3 Normalize(_In_ const Vector3& V);
		extern float Dot(_In_ const Vector3& A, _In_ const Vector3& B);
		extern Vector3 Cross(_In_ const Vector3& A, const Vector3& B);
		extern float Lerp(_In_ float A, _In_ float B, _In_ float X);
		extern Vector3 Lerp(_In_ const Vector3& A, _In_ const Vector3& B, _In_ float X);
	}
}
