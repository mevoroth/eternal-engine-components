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
			return ScaleMatrix(Scaling) * RotationMatrix(Rotation) * TranslationMatrix(Translation);
		}
	}
}
