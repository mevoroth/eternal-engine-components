#ifndef _CAMERA_HPP_
#define _CAMERA_HPP_

#include "ComponentsSettings.hpp"
#include "Types/Types.hpp"

namespace Eternal
{
	namespace Components
	{
		using namespace Types;

		class Camera
		{
		public:
			Camera(float Near, float Far);
			void GetProjectionMatrix(Matrix4x4* ProjectionMatrix) const;
			void SetNear(float Near);
			void SetFar(float Far);

		protected:
			//Matrix4x4 _Model;
			Matrix4x4 _Proj;

			virtual void _UpdateMatrix() = 0;

			float _Near;
			float _Far;
		};
	}
}

#endif
