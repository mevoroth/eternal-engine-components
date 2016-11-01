#include "Light/SpotLight.hpp"

#include "Macros/Macros.hpp"

using namespace Eternal::Components;

SpotLight::SpotLight(_In_ float FOV, _In_ const Vector3& Color, _In_ float Distance, _In_ float Intensity)
	: Light(Color, Distance, Intensity)
	, _FOV(FOV)
{
}

void SpotLight::SetFOV(_In_ float FOV)
{
	ETERNAL_ASSERT(FOV >= 1.0f);
	_FOV = FOV;
}
