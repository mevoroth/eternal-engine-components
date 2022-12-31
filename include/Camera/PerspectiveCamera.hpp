#pragma once

#include "Camera.hpp"

namespace Eternal
{
	namespace Components
	{
		class PerspectiveCamera final : public Camera
		{
		public:
			PerspectiveCamera(_In_ float InNear, _In_ float InFar, _In_ float InYFOV, _In_ float InScreenRatio);

			void SetYFOV(_In_ float InYFOV);
			void SetScreenRatio(_In_ float InRatio);

		protected:
			virtual void _UpdateViewToClip() override final;

		private:
			float _YFOV			= 0.78539816339f; // 90° / 2
			float _ScreenRatio	= 16.f / 9.f;
		};
	}
}
