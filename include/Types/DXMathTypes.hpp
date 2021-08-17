#pragma once

#include <DirectXMath.h>

namespace Eternal
{
	namespace Types
	{
		using namespace DirectX;

		struct Vector3;

		struct Matrix4x4 : public XMFLOAT4X4A
		{
			static Matrix4x4 Identity;

			using XMFLOAT4X4A::XMFLOAT4X4A;
		};

		struct PerspectiveLHMatrix : public Matrix4x4
		{
			PerspectiveLHMatrix(_In_ float InNear, _In_ float InFar, _In_ float InYFOV, _In_ float InScreenRatio);
		};

		struct InversePerspectiveLHMatrix : public Matrix4x4
		{
			InversePerspectiveLHMatrix(_In_ float InNear, _In_ float InFar, _In_ float InYFOV, _In_ float InScreenRatio);
		};

		struct ReverseZPerspectiveLHMatrix : public PerspectiveLHMatrix
		{
			ReverseZPerspectiveLHMatrix(_In_ float InNear, _In_ float InFar, _In_ float InYFOV, _In_ float InScreenRatio);
		};

		struct ReverseZInversePerspectiveLHMatrix : public InversePerspectiveLHMatrix
		{
			ReverseZInversePerspectiveLHMatrix(_In_ float InNear, _In_ float InFar, _In_ float InYFOV, _In_ float InScreenRatio);
		};

		struct OrthographicLHMatrix : public Matrix4x4
		{
			OrthographicLHMatrix(_In_ float InNear, _In_ float InFar, _In_ float InWidth, _In_ float InHeight);
		};

		struct InverseOrthographicLHMatrix : public Matrix4x4
		{
			InverseOrthographicLHMatrix(_In_ float InNear, _In_ float InFar, _In_ float InWidth, _In_ float InHeight);
		};

		struct ReverseZOrthographicLHMatrix : public OrthographicLHMatrix
		{
			ReverseZOrthographicLHMatrix(_In_ float InNear, _In_ float InFar, _In_ float InWidth, _In_ float InHeight);
		};

		struct ReverseZInverseOrthographicLHMatrix : public InverseOrthographicLHMatrix
		{
			ReverseZInverseOrthographicLHMatrix(_In_ float InNear, _In_ float InFar, _In_ float InWidth, _In_ float InHeight);
		};

		struct LookToLHMatrix : public Matrix4x4
		{
			LookToLHMatrix(_In_ const Vector3& InPosition, _In_ const Vector3& InForward, _In_ const Vector3& InUp);
		};

		struct Vector2 : public XMFLOAT2
		{
			static Vector2 One;
			static Vector2 Zero;

			using XMFLOAT2::XMFLOAT2;

			Vector2()
				: Vector2(0.0f)
			{
			}
			Vector2(_In_ float Scalar)
				: XMFLOAT2(Scalar, Scalar)
			{
			}
		};

		struct Vector3 : public XMFLOAT3
		{
			static Vector3 One;
			static Vector3 Zero;
			static Vector3 Right;
			static Vector3 Up;
			static Vector3 Forward;
			static Vector3 Left;
			static Vector3 Down;
			static Vector3 Backward;

			using XMFLOAT3::XMFLOAT3;

			Vector3()
				: Vector3(0.0f)
			{
			}
			Vector3(_In_ float Scalar)
				: XMFLOAT3(Scalar, Scalar, Scalar)
			{
			}
		};
		
		struct Vector4 : public XMFLOAT4A
		{
			static Vector4 One;
			static Vector4 Zero;
			static Vector4 ZeroPosition;
			static Vector4 RightPosition;
			static Vector4 UpPosition;
			static Vector4 ForwardPosition;
			static Vector4 LeftPosition;
			static Vector4 DownPosition;
			static Vector4 BackwardPosition;

			using XMFLOAT4A::XMFLOAT4A;

			Vector4()
				: Vector4(0.0f)
			{
			}
			Vector4(_In_ float Scalar)
				: XMFLOAT4A(Scalar, Scalar, Scalar, Scalar)
			{
			}
			Vector4(_In_ const Vector3& InPosition, float InW)
				: XMFLOAT4A(InPosition.x, InPosition.y, InPosition.z, InW)
			{
			}
		};

		struct Quaternion : public Vector4
		{
			static Quaternion QuaternionIdentity;

			using Vector4::Vector4;
		};
	}
}
