#include "Transform/Transform.hpp"

#include <DirectXMath.h>

namespace Eternal
{
	namespace Components
	{
		Transform::Transform()
		{
		}

		Transform::Transform(_In_ const Vector3& InTranslation, _In_ const Quaternion& InRotation, _In_ const Vector3& InScaling)
			: Translation(InTranslation)
			, Rotation(InRotation)
			, Scaling(InScaling)
		{
		}

		void Transform::SetTranslation(_In_ const Vector3& InT)
		{
			Translation = InT;
		}
		void Transform::SetRotation(_In_ const Quaternion& InR)
		{
			Rotation = InR;
		}
		void Transform::SetScaling(_In_ const Vector3& InS)
		{
			Scaling = InS;
		}
		void Transform::Translate(_In_ const Vector3& InD)
		{
			Translation += InD;
		}
		void Transform::Rotate(_In_ const Vector4& InR)
		{
			Rotation *= InR;
		}
		void Transform::Rotate(_In_ const Vector3& R)
		{
			XMVECTOR NewRotation = XMQuaternionMultiply(
				XMLoadFloat4(&Rotation),
				XMQuaternionRotationRollPitchYaw(R.x, R.y, R.z)
			);
			XMStoreFloat4(&Rotation, NewRotation);
		}
		void Transform::Scale(_In_ const Vector3& InS)
		{
			Scaling *= InS;
		}

		Matrix4x4 Transform::GetViewToWorld() const
		{
			//XMMATRIX ModelMatrix = XMMatrixScalingFromVector(XMLoadFloat3(&Scaling))
			//	* XMMatrixRotationQuaternion(XMLoadFloat4(&Rotation))
			//	* XMMatrixTranslationFromVector(XMLoadFloat3(&Translation));
			XMMATRIX ScalingMatrix = XMMatrixScalingFromVector(XMLoadFloat3(&Scaling));
			XMMATRIX RotationMatrix = XMMatrixRotationQuaternion(XMLoadFloat4(&Rotation));
			XMMATRIX TranslationMatrix = XMMatrixTranslationFromVector(XMLoadFloat3(&Translation));
			Matrix4x4 ReturnMatrix;
			XMStoreFloat4x4(&ReturnMatrix, ScalingMatrix * RotationMatrix * TranslationMatrix);
			return ReturnMatrix;
		}
	}
}
