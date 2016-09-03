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
			PerspectiveCamera(_In_ float Near, _In_ float Far, _In_ float FOV);

			void SetFOV(_In_ float FOV);

		protected:
			virtual void _UpdateMatrix() override;

		private:
			float _FOV;
		};
	}
}

#endif
