#pragma once

#include "ComponentsSettings.hpp"
#include "Types/Types.hpp"

namespace Eternal
{
	namespace Components
	{
		using namespace Types;
		class Transform
		{
		public:
			Transform();
			Transform(_In_ const Vector3& InTranslation, _In_ const Quaternion& InRotation, _In_ const Vector3& InScaling);
			const Vector3& GetTranslation() const { return Translation; }
			Vector3& GetTranslation() { return Translation; }
			const Quaternion& GetRotation() const { return Rotation; }
			Quaternion& GetRotation() { return Rotation; }
			const Vector3& GetScaling() const { return Scaling; }
			Vector3& GetScaling() { return Scaling; }
			void SetTranslation(_In_ const Vector3& InTranslation);
			void SetRotation(_In_ const Quaternion& InRotationQuaternion);
			void SetScaling(_In_ const Vector3& InScaling);
			void Translate(_In_ const Vector3& InDeltaTranslation);
			/**
			 * Quaternions
			 */
			void Rotate(_In_ const Quaternion& InDeltaRotationQuaternion);
			/**
			 * Euler angles
			 */
			void Rotate(_In_ const Euler& InDeltaRotationEuler);
			void Scale(_In_ const Vector3& InDeltaScaling);
			Matrix4x4 GetLocalToWorld() const;

			Vector3 RotateVector(_In_ const Vector3& InVector) const;

		private:
			Vector3 Translation	= Vector3::Zero;
			Quaternion Rotation	= Quaternion::QuaternionIdentity;
			Vector3 Scaling		= Vector3::One;
		};
	}
}
