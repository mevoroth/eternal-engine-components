#include "Transform/Transform.hpp"

//#include <DirectXMath.h>

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
		void Transform::Rotate(_In_ const Quaternion& InDeltaRotationQuaternion)
		{
			Rotation *= InDeltaRotationQuaternion;
		}
		void Transform::Rotate(_In_ const Euler& InDeltaRotationEuler)
		{
			Rotation *= InDeltaRotationEuler;
		}
		void Transform::Scale(_In_ const Vector3& InDeltaScaling)
		{
			Scaling *= InDeltaScaling;
		}

		Matrix4x4 Transform::GetLocalToWorld() const
		{
			return ScaleMatrix4x4(Scaling) * RotationMatrix4x4(Rotation) * TranslationMatrix4x4(Translation);
		}

		Vector3 Transform::RotateVector(_In_ const Vector3& InVector) const
		{
			Transform RotationMatrix = *this;
			RotationMatrix.SetScaling(Vector3::One);
			RotationMatrix.SetTranslation(Vector3::Zero);
			Vector4 VectorPoint(InVector, 1.0f);
			Matrix4x4 LocalToWorld = RotationMatrix.GetLocalToWorld();
			Vector4 RotateVectorPoint = LocalToWorld * VectorPoint;
			return Vector3(RotateVectorPoint.x, RotateVectorPoint.y, RotateVectorPoint.z);
		}
	}
}
