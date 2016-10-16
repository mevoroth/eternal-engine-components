#include "Types/Types.hpp"

#include "Macros/Macros.hpp"
#include <cmath>

using namespace Eternal::Types;

namespace Eternal
{
	namespace Types
	{
		Matrix4x4 NewIdentity()
		{
			return Matrix4x4(
				1.f, 0.f, 0.f, 0.f,
				0.f, 1.f, 0.f, 0.f,
				0.f, 0.f, 1.f, 0.f,
				0.f, 0.f, 0.f, 1.f
			);
		}


		Matrix4x4 operator*(_In_ const Matrix4x4& A, _In_ const Matrix4x4& B)
		{
			Matrix4x4 ReturnMatrix;
			XMStoreFloat4x4(&ReturnMatrix, XMMatrixMultiply(XMLoadFloat4x4(&A), XMLoadFloat4x4(&B)));
			return ReturnMatrix;
		}

		Matrix4x4& operator*=(_In_ Matrix4x4& A, const _In_ Matrix4x4& B)
		{
			XMStoreFloat4x4(&A, XMMatrixMultiply(XMLoadFloat4x4(&A), XMLoadFloat4x4(&B)));
			return A;
		}

		Vector4 operator+(_In_ const Vector4& A, _In_ const Vector4& B)
		{
			return Vector4(A.x + B.x, A.y + B.y, A.z + B.z, A.w + B.w);
		}
		Vector3 operator+(_In_ const Vector3& A, _In_ const Vector3& B)
		{
			return Vector3(A.x + B.x, A.y + B.y, A.z + B.z);
		}
		Vector2 operator+(_In_ const Vector2& A, _In_ const Vector2& B)
		{
			return Vector2(A.x + B.x, A.y + B.y);
		}
		Vector4 operator-(_In_ const Vector4& A, _In_ const Vector4& B)
		{
			return Vector4(A.x - B.x, A.y - B.y, A.z - B.z, A.w - B.w);
		}
		Vector3 operator-(_In_ const Vector3& A, _In_ const Vector3& B)
		{
			return Vector3(A.x - B.x, A.y - B.y, A.z - B.z);
		}
		Vector2 operator-(_In_ const Vector2& A, _In_ const Vector2& B)
		{
			return Vector2(A.x - B.x, A.y - B.y);
		}
		Vector4 operator*(_In_ const Vector4& A, _In_ const Vector4& B)
		{
			return Vector4(A.x * B.x, A.y * B.y, A.z * B.z, A.w * B.w);
		}
		Vector3 operator*(_In_ const Vector3& A, _In_ const Vector3& B)
		{
			return Vector3(A.x * B.x, A.y * B.y, A.z * B.z);
		}
		Vector2 operator*(_In_ const Vector2& A, _In_ const Vector2& B)
		{
			return Vector2(A.x * B.x, A.y * B.y);
		}
		Vector4& operator+=(_In_ Vector4& A, _In_ const Vector4& B)
		{
			A = Vector4(A.x + B.x, A.y + B.y, A.z + B.z, A.w + B.w);
			return A;
		}
		Vector3& Eternal::Types::operator+=(_In_ Vector3& A, _In_ const Vector3& B)
		{
			A = Vector3(A.x + B.x, A.y + B.y, A.z + B.z);
			return A;
		}
		Vector2& operator+=(_In_ Vector2& A, _In_ const Vector2& B)
		{
			A = Vector2(A.x + B.x, A.y + B.y);
			return A;
		}
		Vector4& operator-=(_In_ Vector4& A, _In_ const Vector4& B)
		{
			A = Vector4(A.x - B.x, A.y - B.y, A.z - B.z, A.w - B.w);
			return A;
		}
		Vector3& operator-=(_In_ Vector3& A, _In_ const Vector3& B)
		{
			A = Vector3(A.x - B.x, A.y - B.y, A.z - B.z);
			return A;
		}
		Vector2& operator-=(_In_ Vector2& A, _In_ const Vector2& B)
		{
			A = Vector2(A.x - B.x, A.y - B.y);
			return A;
		}
		Vector4& operator*=(_In_ Vector4& A, _In_ const Vector4& B)
		{
			A = Vector4(A.x * B.x, A.y * B.y, A.z * B.z, A.w * B.w);
			return A;
		}
		Vector3& operator*=(_In_ Vector3& A, _In_ const Vector3& B)
		{
			A = Vector3(A.x * B.x, A.y * B.y, A.z * B.z);
			return A;
		}
		Vector2& operator*=(_In_ Vector2& A, _In_ const Vector2& B)
		{
			A = Vector2(A.x * B.x, A.y * B.y);
			return A;
		}
		Vector4 operator*(_In_ const Vector4& A, _In_ float B)
		{
			return Vector4(
				A.x * B,
				A.y * B,
				A.z * B,
				A.w * B
			);
		}
		Vector4 operator*(_In_ float A, _In_ const Vector4& B)
		{
			return B * A;
		}
		Vector3 operator*(_In_ const Vector3& A, _In_ float B)
		{
			return Vector3(
				A.x * B,
				A.y * B,
				A.z * B
			);
		}
		Vector3 operator*(_In_ float A, _In_ const Vector3& B)
		{
			return B * A;
		}
		Vector2 operator*(_In_ const Vector2& A, _In_ float B)
		{
			return Vector2(
				A.x * B,
				A.y * B
			);
		}
		Vector2 operator*(_In_ float A, _In_ const Vector2& B)
		{
			return B * A;
		}
		Vector4 operator*(_In_ const Matrix4x4& A, _In_ const Vector4& B)
		{
			Vector4 ReturnVector;
			XMStoreFloat4(&ReturnVector, XMVector4Transform(
				XMLoadFloat4(&B),
				XMLoadFloat4x4(&A)
			));
			return ReturnVector;
		}

		bool operator==(_In_ const Vector4& A, _In_ const Vector4& B)
		{
			return A.x == B.x
				&& A.y == B.y
				&& A.z == B.z
				&& A.w == B.w;
		}
		bool operator==(_In_ const Vector3& A, _In_ const Vector3& B)
		{
			return A.x == B.x
				&& A.y == B.y
				&& A.z == B.z;
		}
		bool operator<(_In_ const Vector3& A, _In_ const Vector3& B)
		{
			return A.x < B.x
				&& A.y < B.y
				&& A.z < B.z;
		}
		bool operator>(_In_ const Vector3& A, _In_ const Vector3& B)
		{
			return A.x > B.x
				&& A.y > B.y
				&& A.z > B.z;
		}
		bool operator<=(_In_ const Vector3& A, _In_ const Vector3& B)
		{
			return (A.x < B.x || A.x == B.x)
				&& (A.y < B.y || A.y == B.y)
				&& (A.z < B.z || A.z == B.z);
		}
		bool operator>=(_In_ const Vector3& A, _In_ const Vector3& B)
		{
			return (A.x > B.x || A.x == B.x)
				&& (A.y > B.y || A.y == B.y)
				&& (A.z > B.z || A.z == B.z);
		}

		Matrix4x4 NewOrthoLH(_In_ float Top, _In_ float Bottom, _In_ float Left, _In_ float Right, _In_ float Near, _In_ float Far)
		{
			float DepthRange	= 1.f / (Far - Near);
			float XRange		= 1.f / (Right - Left);
			float YRange		= 1.f / (Top - Bottom);

			Matrix4x4 ProjMatrix(
				2.f * XRange,				0.f,						0.f,					0.f,
				0.f,						2.f * YRange,				0.f,					0.f,
				0.f,						0.f,						DepthRange,				0.f,
				- (Left + Right) * XRange,	- (Top + Bottom) * YRange,	- Near * DepthRange,	1.f
			);

			return ProjMatrix;
		}

		Matrix4x4 NewPerpectiveLH(_In_ float YFOV, _In_ float ScreenRatio, _In_ float Near, _In_ float Far)
		{
			float Height		= tan(YFOV / 2.f);
			float Width			= Height / ScreenRatio;
			float DepthRange	= 1.f / (Far - Near);

			Matrix4x4 ProjMatrix(
				Width,	0.f,	0.f,					0.f,
				0.f,	Height,	0.f,					0.f,
				0.f,	0.f,	DepthRange * Far,		1.f,
				0.f,	0.f,	-(Near + DepthRange),	0.f
			);

			return ProjMatrix;
		}

		Matrix4x4 NewLookToLH(_In_ const Vector3& Position, _In_ const Vector3& Direction, _In_ const Vector3& Up)
		{
			Vector3 NormalizedDirection	= Normalize(Direction);
			Vector3 NormalizedUp		= Normalize(Up);
			Vector3 NormalizedRight		= Normalize(Cross(NormalizedUp, NormalizedDirection));

			Matrix4x4 LookToMatrix(
				NormalizedRight.x,		NormalizedRight.y,		NormalizedRight.z,		0.f,
				NormalizedUp.x,			NormalizedUp.y,			NormalizedUp.z,			0.f,
				NormalizedDirection.x,	NormalizedDirection.y,	NormalizedDirection.z,	0.f,
				-Position.x,			-Position.y,			-Position.z,			1.f
			);

			return LookToMatrix;
		}

		float SquareLength(_In_ const Vector3& V)
		{
			return V.x*V.x + V.y*V.y + V.z*V.z;
		}
		float Length(_In_ const Vector3& V)
		{
			return sqrt(SquareLength(V));
		}
		Vector3 Normalize(_In_ const Vector3& V)
		{
			float VectorLength = Length(V);

			ETERNAL_ASSERT(VectorLength > 0.f);

			return Vector3(
				V.x / VectorLength,
				V.y / VectorLength,
				V.z / VectorLength
			);
		}

		Vector3 Cross(_In_ const Vector3& A, _In_ const Vector3& B)
		{
			return Vector3(
				A.y * B.z - A.z * B.y,
				A.z * B.x - A.x * B.z,
				A.x * B.y - A.y * B.x
			);
		}

		Vector3 Min(_In_ const Vector3& A, _In_ const Vector3& B)
		{
			return A <= B ? A : B;
		}
		Vector3 Max(_In_ const Vector3& A, _In_ const Vector3& B)
		{
			return A >= B ? A : B;
		}
		void Transpose(_Inout_ Matrix4x4& A)
		{
			XMStoreFloat4x4(&A, XMMatrixTranspose(XMLoadFloat4x4(&A)));
		}
		void Inverse(_Inout_ Matrix4x4& A)
		{
			XMStoreFloat4x4(&A, XMMatrixInverse(nullptr, XMLoadFloat4x4(&A)));
		}
	}
}
