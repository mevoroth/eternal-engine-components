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
			Transform(_In_ const Vector3& Translation, _In_ const Quaternion& Rotation, _In_ const Vector3& Scaling);
			const Vector3& GetTranslation() const { return Translation; }
			Vector3& GetTranslation() { return Translation; }
			const Quaternion& GetRotation() const { return Rotation; }
			const Vector3& GetScaling() const { return Scaling; }
			void SetTranslation(_In_ const Vector3& T);
			void SetRotation(_In_ const Quaternion& R);
			void SetScaling(_In_ const Vector3& S);
			void Translate(_In_ const Vector3& D);
			/**
			 * Quaternions
			 */
			void Rotate(_In_ const Quaternion& Q);
			/**
			 * Euler angles
			 */
			void Rotate(_In_ const Euler& R);
			void Scale(_In_ const Vector3& S);
			Matrix4x4 GetLocalToWorld() const;

			Vector3 RotateVector(_In_ const Vector3& InVector) const;

		private:
			Vector3 Translation	= Vector3::Zero;
			Quaternion Rotation	= Quaternion::QuaternionIdentity;
			Vector3 Scaling		= Vector3::One;
		};
	}
}
