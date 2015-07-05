#ifndef _PERSPECTIVE_CAMERA_HPP_
#define _PERSPECTIVE_CAMERA_HPP_

#include "Camera.hpp"

namespace Eternal
{
	namespace Components
	{
		class PerspectiveCamera : public Camera
		{
		public:
			PerspectiveCamera(float Near, float Far, float FOV);

			void SetFOV(float FOV);

		protected:
			virtual void _UpdateMatrix() override;

		private:
			float _FOV;
		};
	}
}

#endif
