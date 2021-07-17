#include "Types/Types.hpp"

#include <cmath>

using namespace Eternal::Types;

namespace Eternal
{
	namespace Types
	{
		Matrix4x4 Matrix4x4::Identity(
			1.f, 0.f, 0.f, 0.f,
			0.f, 1.f, 0.f, 0.f,
			0.f, 0.f, 1.f, 0.f,
			0.f, 0.f, 0.f, 1.f
		);
		Vector4 Vector4::ZeroPosition(0.0f, 0.0f, 0.0f, 1.0f);
		Vector4 Vector4::QuaternionIdentity(0.0f, 0.0f, 0.0f, 1.0f);

		Vector3 Vector3::Right(		 1.0f,  0.0f,  0.0f);
		Vector3 Vector3::Up(		 0.0f,  1.0f,  0.0f);
		Vector3 Vector3::Forward(	 0.0f,  0.0f,  1.0f);
		Vector3 Vector3::Left(		-1.0f,  0.0f,  0.0f);
		Vector3 Vector3::Down(		 0.0f, -1.0f,  0.0f);
		Vector3 Vector3::Backward(	 0.0f,  0.0f, -1.0f);

		Vector4 Vector4::One(1.0f);
		Vector3 Vector3::One(1.0f);
		Vector2 Vector2::One(1.0f);
		Vector4 Vector4::Zero(0.0f);
		Vector3 Vector3::Zero(0.0f);
		Vector2 Vector2::Zero(0.0f);

		Matrix4x4 operator*(_In_ const Matrix4x4& A, _In_ const Matrix4x4& B)
		{
			Matrix4x4 ReturnMatrix;
			XMStoreFloat4x4A(&ReturnMatrix, XMMatrixMultiply(XMLoadFloat4x4A(&A), XMLoadFloat4x4A(&B)));
			return ReturnMatrix;
		}

		Matrix4x4& operator*=(_In_ Matrix4x4& A, const _In_ Matrix4x4& B)
		{
			XMStoreFloat4x4(&A, XMMatrixMultiply(XMLoadFloat4x4(&A), XMLoadFloat4x4(&B)));
			return A;
		}

		Vector4 operator+(_In_ const Vector4& A, _In_ const Vector4& B)
		{
			Vector4 Result;
			XMStoreFloat4A(&Result, XMVectorAdd(XMLoadFloat4A(&A), XMLoadFloat4A(&B)));
			return Result;
		}
		Vector3 operator+(_In_ const Vector3& A, _In_ const Vector3& B)
		{
			Vector3 Result;
			XMStoreFloat3(&Result, XMVectorAdd(XMLoadFloat3(&A), XMLoadFloat3(&B)));
			return Result;
		}
		Vector2 operator+(_In_ const Vector2& A, _In_ const Vector2& B)
		{
			Vector2 Result;
			XMStoreFloat2(&Result, XMVectorAdd(XMLoadFloat2(&A), XMLoadFloat2(&B)));
			return Result;
		}
		Vector4 operator-(_In_ const Vector4& A, _In_ const Vector4& B)
		{
			Vector4 Result;
			XMStoreFloat4A(&Result, XMVectorSubtract(XMLoadFloat4A(&A), XMLoadFloat4A(&B)));
			return Result;
		}
		Vector3 operator-(_In_ const Vector3& A, _In_ const Vector3& B)
		{
			Vector3 Result;
			XMStoreFloat3(&Result, XMVectorSubtract(XMLoadFloat3(&A), XMLoadFloat3(&B)));
			return Result;
		}
		Vector2 operator-(_In_ const Vector2& A, _In_ const Vector2& B)
		{
			Vector2 Result;
			XMStoreFloat2(&Result, XMVectorSubtract(XMLoadFloat2(&A), XMLoadFloat2(&B)));
			return Result;
		}
		Vector4 operator*(_In_ const Vector4& A, _In_ const Vector4& B)
		{
			Vector4 Result;
			XMStoreFloat4A(&Result, XMVectorMultiply(XMLoadFloat4A(&A), XMLoadFloat4A(&B)));
			return Result;
		}
		Vector3 operator*(_In_ const Vector3& A, _In_ const Vector3& B)
		{
			Vector3 Result;
			XMStoreFloat3(&Result, XMVectorMultiply(XMLoadFloat3(&A), XMLoadFloat3(&B)));
			return Result;
		}
		Vector2 operator*(_In_ const Vector2& A, _In_ const Vector2& B)
		{
			Vector2 Result;
			XMStoreFloat2(&Result, XMVectorMultiply(XMLoadFloat2(&A), XMLoadFloat2(&B)));
			return Result;
		}
		Vector4& operator+=(_In_ Vector4& A, _In_ const Vector4& B)
		{
			XMStoreFloat4A(&A, XMVectorAdd(XMLoadFloat4A(&A), XMLoadFloat4A(&B)));
			return A;
		}
		Vector3& Eternal::Types::operator+=(_In_ Vector3& A, _In_ const Vector3& B)
		{
			XMStoreFloat3(&A, XMVectorAdd(XMLoadFloat3(&A), XMLoadFloat3(&B)));
			return A;
		}
		Vector2& operator+=(_In_ Vector2& A, _In_ const Vector2& B)
		{
			XMStoreFloat2(&A, XMVectorAdd(XMLoadFloat2(&A), XMLoadFloat2(&B)));
			return A;
		}
		Vector4& operator-=(_In_ Vector4& A, _In_ const Vector4& B)
		{
			XMStoreFloat4A(&A, XMVectorSubtract(XMLoadFloat4A(&A), XMLoadFloat4A(&B)));
			return A;
		}
		Vector3& operator-=(_In_ Vector3& A, _In_ const Vector3& B)
		{
			XMStoreFloat3(&A, XMVectorSubtract(XMLoadFloat3(&A), XMLoadFloat3(&B)));
			return A;
		}
		Vector2& operator-=(_In_ Vector2& A, _In_ const Vector2& B)
		{
			XMStoreFloat2(&A, XMVectorSubtract(XMLoadFloat2(&A), XMLoadFloat2(&B)));
			return A;
		}
		Vector4& operator*=(_In_ Vector4& A, _In_ const Vector4& B)
		{
			XMStoreFloat4A(&A, XMVectorMultiply(XMLoadFloat4A(&A), XMLoadFloat4A(&B)));
			return A;
		}
		Vector3& operator*=(_In_ Vector3& A, _In_ const Vector3& B)
		{
			XMStoreFloat3(&A, XMVectorMultiply(XMLoadFloat3(&A), XMLoadFloat3(&B)));
			return A;
		}
		Vector2& operator*=(_In_ Vector2& A, _In_ const Vector2& B)
		{
			XMStoreFloat2(&A, XMVectorMultiply(XMLoadFloat2(&A), XMLoadFloat2(&B)));
			return A;
		}
		Vector4 operator*(_In_ const Vector4& A, _In_ float B)
		{
			Vector4 Result;
			XMStoreFloat4A(&Result, XMVectorMultiply(XMLoadFloat4A(&A), XMVectorReplicate(B)));
			return Result;
		}
		Vector4 operator*(_In_ float A, _In_ const Vector4& B)
		{
			return B * A;
		}
		Vector3 operator*(_In_ const Vector3& A, _In_ float B)
		{
			Vector3 Result;
			XMStoreFloat3(&Result, XMVectorMultiply(XMLoadFloat3(&A), XMVectorReplicate(B)));
			return Result;
		}
		Vector3 operator*(_In_ float A, _In_ const Vector3& B)
		{
			return B * A;
		}
		Vector2 operator*(_In_ const Vector2& A, _In_ float B)
		{
			Vector2 Result;
			XMStoreFloat2(&Result, XMVectorMultiply(XMLoadFloat2(&A), XMVectorReplicate(B)));
			return Result;
		}
		Vector2 operator*(_In_ float A, _In_ const Vector2& B)
		{
			return B * A;
		}
		Vector2 operator/(_In_ const Vector2& A, _In_ float B)
		{
			Vector2 Result;
			XMStoreFloat2(&Result, XMVectorDivide(XMLoadFloat2(&A), XMVectorReplicate(B)));
			return Result;
		}
		Vector4 operator*(_In_ const Matrix4x4& A, _In_ const Vector4& B)
		{
			Vector4 Result;
			XMStoreFloat4A(&Result, XMVector4Transform(
				XMLoadFloat4A(&B),
				XMLoadFloat4x4A(&A)
			));
			return Result;
		}

		bool operator==(_In_ const Vector4& A, _In_ const Vector4& B)
		{
			uint32_t ComparisonResult;
			XMVectorEqualR(&ComparisonResult, XMLoadFloat4A(&A), XMLoadFloat4A(&B));
			return XMComparisonAllTrue(ComparisonResult);
		}
		bool operator==(_In_ const Vector3& A, _In_ const Vector3& B)
		{
			uint32_t ComparisonResult;
			XMVectorEqualR(&ComparisonResult, XMLoadFloat3(&A), XMLoadFloat3(&B));
			return XMComparisonAllTrue(ComparisonResult);
		}
		Vector3 operator<(_In_ const Vector3& A, _In_ const Vector3& B)
		{
			Vector3 Result;
			XMStoreFloat3(&Result, XMVectorLess(XMLoadFloat3(&A), XMLoadFloat3(&B)));
			return Result;
		}
		Vector3 operator>(_In_ const Vector3& A, _In_ const Vector3& B)
		{
			Vector3 Result;
			XMStoreFloat3(&Result, XMVectorGreater(XMLoadFloat3(&A), XMLoadFloat3(&B)));
			return Result;
		}
		Vector3 operator<=(_In_ const Vector3& A, _In_ const Vector3& B)
		{
			Vector3 Result;
			XMStoreFloat3(&Result, XMVectorLessOrEqual(XMLoadFloat3(&A), XMLoadFloat3(&B)));
			return Result;
		}
		Vector3 operator>=(_In_ const Vector3& A, _In_ const Vector3& B)
		{
			Vector3 Result;
			XMStoreFloat3(&Result, XMVectorGreaterOrEqual(XMLoadFloat3(&A), XMLoadFloat3(&B)));
			return Result;
		}
		Vector2 operator<(_In_ const Vector2& A, _In_ const Vector2& B)
		{
			Vector2 Result;
			XMStoreFloat2(&Result, XMVectorLess(XMLoadFloat2(&A), XMLoadFloat2(&B)));
			return Result;
		}
		Vector2 operator>=(_In_ const Vector2& A, _In_ const Vector2& B)
		{
			Vector2 Result;
			XMStoreFloat2(&Result, XMVectorGreaterOrEqual(XMLoadFloat2(&A), XMLoadFloat2(&B)));
			return Result;
		}

		Vector4 operator-(_In_ const Vector4& InVector)
		{
			Vector4 Result;
			XMStoreFloat4A(&Result, XMVectorNegate(XMLoadFloat4A(&InVector)));
			return Result;
		}

		Vector3 operator-(_In_ const Vector3& InVector)
		{
			Vector3 Result;
			XMStoreFloat3(&Result, XMVectorNegate(XMLoadFloat3(&InVector)));
			return Result;
		}

		Vector2 operator-(_In_ const Vector2& InVector)
		{
			Vector2 Result;
			XMStoreFloat2(&Result, XMVectorNegate(XMLoadFloat2(&InVector)));
			return Result;
		}

		Vector4 Min(_In_ const Vector4& A, _In_ const Vector4& B)
		{
			Vector4 Result;
			XMStoreFloat4A(&Result, XMVectorMin(XMLoadFloat4A(&A), XMLoadFloat4A(&B)));
			return Result;
		}
		Vector3 Min(_In_ const Vector3& A, _In_ const Vector3& B)
		{
			Vector3 Result;
			XMStoreFloat3(&Result, XMVectorMin(XMLoadFloat3(&A), XMLoadFloat3(&B)));
			return Result;
		}
		Vector2 Min(_In_ const Vector2& A, _In_ const Vector2& B)
		{
			Vector2 Result;
			XMStoreFloat2(&Result, XMVectorMin(XMLoadFloat2(&A), XMLoadFloat2(&B)));
			return Result;
		}
		Vector4 Max(_In_ const Vector4& A, _In_ const Vector4& B)
		{
			Vector4 Result;
			XMStoreFloat4A(&Result, XMVectorMax(XMLoadFloat4A(&A), XMLoadFloat4A(&B)));
			return Result;
		}
		Vector3 Max(_In_ const Vector3& A, _In_ const Vector3& B)
		{
			Vector3 Result;
			XMStoreFloat3(&Result, XMVectorMax(XMLoadFloat3(&A), XMLoadFloat3(&B)));
			return Result;
		}
		Vector2 Max(_In_ const Vector2& A, _In_ const Vector2& B)
		{
			Vector2 Result;
			XMStoreFloat2(&Result, XMVectorMin(XMLoadFloat2(&A), XMLoadFloat2(&B)));
			return Result;
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

		Matrix4x4 NewPerspectiveLH(_In_ float YFOV, _In_ float ScreenRatio, _In_ float Near, _In_ float Far)
		{
			float Height		= tan(YFOV / 2.f);
			float Width			= Height / ScreenRatio;
			float DepthRange	= Far / (Far - Near);

			//Matrix4x4 ProjMatrix/*(
			//	Width,	0.f,	0.f,					0.f,
			//	0.f,	Height,	0.f,					0.f,
			//	0.f,	0.f,	DepthRange,				1.f,
			//	0.f,	0.f,	-Near * DepthRange,		0.f
			//)*/;
			//XMStoreFloat4x4(&ProjMatrix, XMMatrixPerspectiveFovLH(YFOV, ScreenRatio, Near, Far));

			Matrix4x4 ProjMatrix(
				Width,	0.f,	0.f,					0.f,
				0.f,	Height,	0.f,					0.f,
				0.f,	0.f,	DepthRange,				1.f,
				0.f,	0.f,	-(Near * DepthRange),	0.f
			);

			return ProjMatrix;
		}

		Matrix4x4 NewLookToLH(_In_ const Vector3& Position, _In_ const Vector3& Direction, _In_ const Vector3& Up)
		{
			Vector3 NormalizedDirection	= Normalize(Direction);
			Vector3 NormalizedUp		= Normalize(Up);
			Vector3 NormalizedRight		= Normalize(Cross(NormalizedUp, NormalizedDirection));

			Vector3 NegativePosition(-Position.x, -Position.y, -Position.z);
			Vector3 TransformedPosition(
				Dot(NormalizedRight, NegativePosition),
				Dot(NormalizedUp, NegativePosition),
				Dot(NormalizedDirection, NegativePosition)
			);

			Matrix4x4 LookToMatrix(
				NormalizedRight.x,		NormalizedUp.x,			NormalizedDirection.x,	0.f,
				NormalizedRight.y,		NormalizedUp.y,			NormalizedDirection.y,	0.f,
				NormalizedRight.z,		NormalizedUp.z,			NormalizedDirection.z,	0.f,
				TransformedPosition.x,	TransformedPosition.y,	TransformedPosition.z,	1.0f
			);

			return LookToMatrix;
		}

		float SquareLength(_In_ const Vector3& V)
		{
			return Dot(V, V);
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
		float Dot(_In_ const Vector3& A, _In_ const Vector3& B)
		{
			return A.x*B.x + A.y*B.y + A.z*B.z;
		}
		Vector3 Cross(_In_ const Vector3& A, _In_ const Vector3& B)
		{
			return Vector3(
				A.y * B.z - A.z * B.y,
				A.z * B.x - A.x * B.z,
				A.x * B.y - A.y * B.x
			);
		}

		void Transpose(_Inout_ Matrix4x4& A)
		{
			XMStoreFloat4x4(&A, XMMatrixTranspose(XMLoadFloat4x4(&A)));
		}
		void Inverse(_Inout_ Matrix4x4& A)
		{
			XMStoreFloat4x4(&A, XMMatrixInverse(nullptr, XMLoadFloat4x4(&A)));
		}
		float Lerp(_In_ float A, _In_ float B, _In_ float X)
		{
			return A + (B - A) * X;
		}
		Vector3 Lerp(_In_ const Vector3& A, _In_ const Vector3& B, _In_ float X)
		{
			return Vector3(
				Lerp(A.x, B.x, X),
				Lerp(A.y, B.y, X),
				Lerp(A.z, B.z, X)
			);
		}
	}
}
