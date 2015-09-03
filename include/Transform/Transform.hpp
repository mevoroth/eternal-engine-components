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
			Transform(const Vector3& Translation, const Vector4& Rotation, const Vector3& Scaling);
			void SetTranslation(const Vector3& D);
			void SetRotation(const Vector4& R);
			void SetScaling(const Vector3& S);
			void Translate(const Vector3& D);
			/**
			 * Quaternions
			 */
			void Rotate(const Vector4& Q);
			/**
			 * Euler angles
			 */
			void Rotate(const Vector3& R);
			void Scale(const Vector3& S);
			Transform GetAbsolute(const Transform& Relative) const;
			Matrix4x4 GetModelMatrix() const;
			Vector3 GetForward() const;
			Vector3 GetUp() const;
			Vector3 GetRight() const;

		private:
			Vector3 Translation;
			Vector4 Rotation;
			Vector3 Scaling;
		};
	}
}

#endif
