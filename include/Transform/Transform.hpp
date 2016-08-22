#ifndef _TRANSFORM_HPP_
#define _TRANSFORM_HPP_

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
			Transform(_In_ const Vector3& Translation, _In_ const Vector4& Rotation, _In_ const Vector3& Scaling);
			const Vector3& GetTranslation() const { return Translation; }
			const Vector4& GetRotation() const { return Rotation; }
			const Vector3& GetScaling() const { return Scaling; }
			void SetTranslation(_In_ const Vector3& T);
			void SetRotation(_In_ const Vector4& R);
			void SetScaling(_In_ const Vector3& S);
			void Translate(_In_ const Vector3& D);
			/**
			 * Quaternions
			 */
			void Rotate(_In_ const Vector4& Q);
			/**
			 * Euler angles
			 */
			void Rotate(_In_ const Vector3& R);
			void Scale(_In_ const Vector3& S);
			Matrix4x4 GetModelMatrix() const;
			//Vector3 GetForward() const;
			//Vector3 GetUp() const;
			//Vector3 GetRight() const;

		private:
			Vector3 Translation;
			Vector4 Rotation;
			Vector3 Scaling;
		};
	}
}

#endif
