#pragma once

#include "Camera/Camera.hpp"

namespace Eternal
{
	namespace Components
	{
		class OrthographicCamera final : public Camera
		{
		public:
			OrthographicCamera(_In_ float InNear, _In_ float InFar, _In_ float InWidth, _In_ float InHeight);

			void SetSize(_In_ float InSize);

		protected:
			virtual void _UpdateViewToClip() override final;

		private:
			float _Width	= 0;
			float _Height	= 0;
		};
	}
}
