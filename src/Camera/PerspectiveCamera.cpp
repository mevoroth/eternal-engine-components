#include "Camera/PerspectiveCamera.hpp"

#include "Graphics/Device.hpp"

using namespace Eternal::Graphics;
using namespace Eternal::Components;

PerspectiveCamera::PerspectiveCamera(float Near, float Far, float FOV)
	: Camera(Near, Far)
	, _FOV(FOV)
{
}

void PerspectiveCamera::SetFOV(float FOV)
{
	_FOV = XMConvertToRadians(FOV);
	_UpdateMatrix();
}

void Eternal::Components::PerspectiveCamera::_UpdateMatrix()
{
	XMStoreFloat4x4(&_Proj,
		XMMatrixPerspectiveFovLH(_FOV, Device::WIDTH / Device::HEIGHT, _Near, _Far));
}
