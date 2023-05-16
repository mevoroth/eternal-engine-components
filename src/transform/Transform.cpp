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

		void Transform::SetTranslation(_In_ const Vector3& InTranslation)
		{
			Translation = InTranslation;
		}
		void Transform::SetRotation(_In_ const Quaternion& InRotationQuaternion)
		{
			Rotation = InRotationQuaternion;
		}
		void Transform::SetScaling(_In_ const Vector3& InScaling)
		{
			Scaling = InScaling;
		}
		void Transform::Translate(_In_ const Vector3& InDeltaTranslation)
		{
			Translation += InDeltaTranslation;
		}
		void Transform::Rotate(_In_ const Vector4& InDeltaRotationQuaternion)
		{
			Rotation *= InDeltaRotationQuaternion;
		}
		void Transform::Rotate(_In_ const Vector3& InDeltaRotationEuler)
		{
			XMVECTOR NewRotation = XMQuaternionMultiply(
				XMLoadFloat4(&Rotation),
				XMQuaternionRotationRollPitchYaw(InDeltaRotationEuler.x, InDeltaRotationEuler.y, InDeltaRotationEuler.z)
			);
			XMStoreFloat4(&Rotation, NewRotation);
		}
		void Transform::Scale(_In_ const Vector3& InDeltaScaling)
		{
			Scaling *= InDeltaScaling;
		}

		Matrix4x4 Transform::GetLocalToWorld() const
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
