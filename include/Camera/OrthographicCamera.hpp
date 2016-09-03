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
			OrthographicCamera(_In_ float Near, _In_ float Far, _In_ float Size);

			void SetSize(_In_ float Size);

		protected:
			virtual void _UpdateMatrix() override;

		private:
			float _Size;
		};
	}
}

#endif
