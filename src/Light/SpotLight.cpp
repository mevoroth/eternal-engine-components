#include "Light/SpotLight.hpp"

namespace Eternal
{
	namespace Components
	{
		SpotLight::SpotLight()
		{
			_LightType = LightType::LIGHT_TYPE_SPOTLIGHT;
		}

		void SpotLight::SetFOV(_In_ float FOV)
		{
			ETERNAL_ASSERT(FOV >= 1.0f);
			_FOV = FOV;
		}
	}
}
