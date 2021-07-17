#pragma once

#include <DirectXMath.h>

namespace Eternal
{
	namespace Types
	{
		using namespace DirectX;

		struct Matrix4x4 : public XMFLOAT4X4A
		{
			static Matrix4x4 Identity;

			using XMFLOAT4X4A::XMFLOAT4X4A;
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
			static Vector4 QuaternionIdentity;

			using XMFLOAT4A::XMFLOAT4A;

			Vector4()
				: Vector4(0.0f)
			{
			}
			Vector4(_In_ float Scalar)
				: XMFLOAT4A(Scalar, Scalar, Scalar, Scalar)
			{
			}
		};
	}
}
