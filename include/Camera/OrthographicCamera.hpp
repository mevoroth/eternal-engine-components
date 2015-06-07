#ifndef _ORTHOGRAPHIC_CAMERA_HPP_
#define _ORTHOGRAPHIC_CAMERA_HPP_

#include "Camera/Camera.hpp"

namespace Eternal
{
	namespace Components
	{
		class OrthographicCamera : public Camera
		{
		public:
			OrthographicCamera(float Near, float Far, float Size);

			void SetSize(float Size);
			virtual void _UpdateMatrix() override;

		private:
			float _Size;
		};
	}
}

#endif
