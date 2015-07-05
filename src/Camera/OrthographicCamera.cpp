#include "Camera/OrthographicCamera.hpp"

using namespace Eternal::Components;

OrthographicCamera::OrthographicCamera(float Near, float Far, float Size)
	: Camera(Near, Far)
	, _Size(Size)
{
	_UpdateMatrix();
}

void OrthographicCamera::SetSize(float Size)
{
	_Size = Size;
	_UpdateMatrix();
}
void OrthographicCamera::_UpdateMatrix()
{
	XMStoreFloat4x4(
		&_Proj,
		XMMatrixOrthographicOffCenterLH(
			0.f, _Size,
			0.f, _Size,
			_Far, _Near
		)
	);
}
