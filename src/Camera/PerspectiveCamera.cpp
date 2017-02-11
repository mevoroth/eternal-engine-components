#include "Camera/PerspectiveCamera.hpp"

#include "Graphics/Device.hpp"

using namespace Eternal::Graphics;
using namespace Eternal::Components;

PerspectiveCamera::PerspectiveCamera(_In_ float Near, _In_ float Far, _In_ float YFOV, _In_ float ScreenRatio)
	: Camera(Near, Far)
	, _YFOV(XMConvertToRadians(YFOV))
	, _ScreenRatio(ScreenRatio)
{
	_UpdateProjectionMatrix();
}

void PerspectiveCamera::SetYFOV(_In_ float XFOV)
{
	_YFOV = XMConvertToRadians(XFOV);
	_UpdateProjectionMatrix();
}

void PerspectiveCamera::SetScreenRatio(_In_ float Ratio)
{
	_ScreenRatio = Ratio;
	_UpdateProjectionMatrix();
}

void PerspectiveCamera::_UpdateProjectionMatrix()
{
	_Proj = NewPerspectiveLH(_YFOV, _ScreenRatio, _Near, _Far);
}
