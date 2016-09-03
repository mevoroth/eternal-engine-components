#include "Camera/PerspectiveCamera.hpp"

#include "Graphics/Device.hpp"

using namespace Eternal::Graphics;
using namespace Eternal::Components;

PerspectiveCamera::PerspectiveCamera(_In_ float Near, _In_ float Far, _In_ float FOV)
	: Camera(Near, Far)
	, _FOV(XMConvertToRadians(FOV))
{
	_UpdateMatrix();
}

void PerspectiveCamera::SetFOV(_In_ float FOV)
{
	_FOV = XMConvertToRadians(FOV);
	_UpdateMatrix();
}

void PerspectiveCamera::_UpdateMatrix()
{
	XMStoreFloat4x4(&_Proj,
		XMMatrixPerspectiveFovLH(_FOV, Device::WIDTH / Device::HEIGHT, _Near, _Far));
}
