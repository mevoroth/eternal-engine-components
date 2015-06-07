#include "Camera/Camera.hpp"

using namespace Eternal::Components;

Camera::Camera(float Near, float Far)
	: _Near(Near)
	, _Far(Far)
{
	_UpdateMatrix();
}

void Camera::GetProjectionMatrix(Matrix4x4* ProjectionMatrix) const
{
	XMMATRIX ProjMatrix = XMMatrixTranspose(XMLoadFloat4x4(&_Proj));
	XMStoreFloat4x4(ProjectionMatrix, ProjMatrix);
}

void Camera::SetNear(float Near)
{
	_Near = Near;
	_UpdateMatrix();
}
void Camera::SetFar(float Far)
{
	_Far = Far;
	_UpdateMatrix();
}
