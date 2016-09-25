#include "Camera/PerspectiveCamera.hpp"

#include "Graphics/Device.hpp"

using namespace Eternal::Graphics;
using namespace Eternal::Components;

PerspectiveCamera::PerspectiveCamera(_In_ float Near, _In_ float Far, _In_ float XFOV, _In_ float ScreenRatio)
	: Camera(Near, Far)
	, _XFOV(XMConvertToRadians(XFOV))
	, _ScreenRatio(ScreenRatio)
{
	_UpdateProjectionMatrix();
}

void PerspectiveCamera::SetXFOV(_In_ float XFOV)
{
	_XFOV = XMConvertToRadians(XFOV);
	_UpdateProjectionMatrix();
}

void PerspectiveCamera::SetScreenRatio(_In_ float Ratio)
{
	_ScreenRatio = Ratio;
	_UpdateProjectionMatrix();
}

void PerspectiveCamera::_UpdateProjectionMatrix()
{
	_Proj = NewPerpectiveLH(_XFOV, _ScreenRatio, _Near, _Far);
}
