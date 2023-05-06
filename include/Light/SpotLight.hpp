#pragma once

#include "Light/Light.hpp"
#include "Light/Shadow.hpp"

namespace Eternal
{
	namespace Components
	{
		class SpotLight : public Light
		{
		public:
			SpotLight();

			void SetFOV(_In_ float FOV);

		private:
			float _FOV = 0.78539816339f; // 45°
		};
	}
}
