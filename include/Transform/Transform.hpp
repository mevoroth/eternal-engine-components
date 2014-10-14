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
		private:
			Vector4 Translation;
			Vector4 Rotation;
			Vector4 Scaling;
		public:
			void Translate(const Vector3& d);
			/**
			 * Quaternions
			 */
			void Rotate(const Vector4& q);
			/**
			 * Euler angles
			 */
			void Rotate(const Vector3& r);
			void Scale(const Vector3& s);
			Matrix4x4 GetModelMatrix() const;
		};
	}
}

#endif
