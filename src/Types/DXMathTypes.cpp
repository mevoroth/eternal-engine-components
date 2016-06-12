#include "Types/Types.hpp"

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


		Matrix4x4 operator*(const Matrix4x4& A, const Matrix4x4& B)
		{
			Matrix4x4 ReturnMatrix;
			XMStoreFloat4x4(&ReturnMatrix, XMMatrixMultiply(XMLoadFloat4x4(&A), XMLoadFloat4x4(&B)));
			return ReturnMatrix;
		}

		Matrix4x4& operator*=(Matrix4x4& A, const Matrix4x4& B)
		{
			XMStoreFloat4x4(&A, XMMatrixMultiply(XMLoadFloat4x4(&A), XMLoadFloat4x4(&B)));
			return A;
		}

		Vector4 operator+(const Vector4& A, const Vector4& B)
		{
			return Vector4(A.x + B.x, A.y + B.y, A.z + B.z, A.w + B.w);
		}
		Vector3 operator+(const Vector3& A, const Vector3& B)
		{
			return Vector3(A.x + B.x, A.y + B.y, A.z + B.z);
		}
		Vector2 operator+(const Vector2& A, const Vector2& B)
		{
			return Vector2(A.x + B.x, A.y + B.y);
		}
		Vector4 operator-(const Vector4& A, const Vector4& B)
		{
			return Vector4(A.x - B.x, A.y - B.y, A.z - B.z, A.w - B.w);
		}
		Vector3 operator-(const Vector3& A, const Vector3& B)
		{
			return Vector3(A.x - B.x, A.y - B.y, A.z - B.z);
		}
		Vector2 operator-(const Vector2& A, const Vector2& B)
		{
			return Vector2(A.x - B.x, A.y - B.y);
		}
		Vector4 operator*(const Vector4& A, const Vector4& B)
		{
			return Vector4(A.x * B.x, A.y * B.y, A.z * B.z, A.w * B.w);
		}
		Vector3 operator*(const Vector3& A, const Vector3& B)
		{
			return Vector3(A.x * B.x, A.y * B.y, A.z * B.z);
		}
		Vector2 operator*(const Vector2& A, const Vector2& B)
		{
			return Vector2(A.x * B.x, A.y * B.y);
		}
		Vector4& operator+=(Vector4& A, const Vector4& B)
		{
			A = Vector4(A.x + B.x, A.y + B.y, A.z + B.z, A.w + B.w);
			return A;
		}
		Vector3& Eternal::Types::operator+=(Vector3& A, const Vector3& B)
		{
			A = Vector3(A.x + B.x, A.y + B.y, A.z + B.z);
			return A;
		}
		Vector2& operator+=(Vector2& A, const Vector2& B)
		{
			A = Vector2(A.x + B.x, A.y + B.y);
			return A;
		}
		Vector4& operator-=(Vector4& A, const Vector4& B)
		{
			A = Vector4(A.x - B.x, A.y - B.y, A.z - B.z, A.w - B.w);
			return A;
		}
		Vector3& operator-=(Vector3& A, const Vector3& B)
		{
			A = Vector3(A.x - B.x, A.y - B.y, A.z - B.z);
			return A;
		}
		Vector2& operator-=(Vector2& A, const Vector2& B)
		{
			A = Vector2(A.x - B.x, A.y - B.y);
			return A;
		}
		Vector4& operator*=(Vector4& A, const Vector4& B)
		{
			A = Vector4(A.x * B.x, A.y * B.y, A.z * B.z, A.w * B.w);
			return A;
		}
		Vector3& operator*=(Vector3& A, const Vector3& B)
		{
			A = Vector3(A.x * B.x, A.y * B.y, A.z * B.z);
			return A;
		}
		Vector2& operator*=(Vector2& A, const Vector2& B)
		{
			A = Vector2(A.x * B.x, A.y * B.y);
			return A;
		}
		Vector4 operator*(const Vector4& A, float B)
		{
			return Vector4(
				A.x * B,
				A.y * B,
				A.z * B,
				A.w * B
			);
		}
		Vector4 operator*(float A, const Vector4& B)
		{
			return B * A;
		}
		Vector3 operator*(const Vector3& A, float B)
		{
			return Vector3(
				A.x * B,
				A.y * B,
				A.z * B
			);
		}
		Vector3 operator*(float A, const Vector3& B)
		{
			return B * A;
		}
		Vector2 operator*(const Vector2& A, float B)
		{
			return Vector2(
				A.x * B,
				A.y * B
			);
		}
		Vector2 operator*(float A, const Vector2& B)
		{
			return B * A;
		}
		Vector4 operator*(const Matrix4x4& A, const Vector4& B)
		{
			Vector4 ReturnVector;
			XMStoreFloat4(&ReturnVector, XMVector4Transform(
				XMLoadFloat4(&B),
				XMLoadFloat4x4(&A)
			));
			return ReturnVector;
		}
	}
}
