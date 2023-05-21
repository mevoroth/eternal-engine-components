#pragma once

#include "Camera.hpp"
#include "Math/Math.hpp"

namespace Eternal
{
	namespace Components
	{
		using namespace Eternal::Math;

		class PerspectiveCamera final : public Camera
		{
		public:
			PerspectiveCamera(_In_ float InNear, _In_ float InFar, _In_ float InYFOV, _In_ float InScreenRatio);

			void SetYFOV(_In_ float InYFOV);
			void SetScreenRatio(_In_ float InRatio);

		protected:
			virtual void _UpdateViewToClip() override final;

		private:
			float _YFOV			= PI * 0.25f; // 90° / 2
			float _ScreenRatio	= 16.f / 9.f;
		};
	}
}
