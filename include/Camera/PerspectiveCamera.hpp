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
			PerspectiveCamera(_In_ float Near, _In_ float Far, _In_ float XFOV, _In_ float ScreenRatio);

			void SetYFOV(_In_ float YFOV);
			void SetScreenRatio(_In_ float Ratio);

		protected:
			virtual void _UpdateProjectionMatrix() override;

		private:
			float _YFOV = 0.78539816339f; // 90° / 2
			float _ScreenRatio = 16.f / 9.f;
		};
	}
}

#endif
