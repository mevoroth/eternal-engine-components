#include "Camera/OrthographicCamera.hpp"

using namespace Eternal::Components;

OrthographicCamera::OrthographicCamera(_In_ float Near, _In_ float Far, _In_ float Size)
	: Camera(Near, Far)
	, _Size(Size)
{
	_UpdateProjectionMatrix();
}

void OrthographicCamera::SetSize(_In_ float Size)
{
	_Size = Size;
	_UpdateProjectionMatrix();
}
void OrthographicCamera::_UpdateProjectionMatrix()
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
