#include "Light/Light.hpp"

using namespace Eternal::Components;

Light::Light(_In_ const Vector3& Color, _In_ float Distance, _In_ float Intensity)
	: _Color(Color)
	, _Distance(Distance)
	, _Intensity(Intensity)
{
}

const Vector3& Light::GetColor() const
{
	return _Color;
}

float Light::GetDistance() const
{
	return _Distance;
}

float Light::GetIntensity() const
{
	return _Intensity;
}

void Light::SetColor(_In_ const Vector3& Color)
{
	_Color = Color;
}

void Light::SetIntensity(_In_ float Intensity)
{
	ETERNAL_ASSERT(Intensity > 0.f);
	_Intensity = Intensity;
}

void Light::SetDistance(_In_ float Distance)
{
	ETERNAL_ASSERT(Distance > 0.f);
	_Distance = Distance;
}
