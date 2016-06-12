#include "Camera/Camera.hpp"

#include <string>

using namespace Eternal::Components;

Camera::Camera(float Near, float Far)
	: _Near(Near)
	, _Far(Far)
{
	XMStoreFloat4x4(
		&_View,
		XMMATRIX(
			1.f, 0.f, 0.f, 0.f,
			0.f, 1.f, 0.f, 0.f,
			0.f, 0.f, 1.f, 0.f,
			0.f, 0.f, 0.f, 1.f
		)
	);

	XMFLOAT4 EyePos(0.f, 0.f, 1.f, 1.f);
	XMFLOAT4 EyeDir(0.f, 0.f, 1.f, 0.f);
	XMFLOAT4 UpDir(0.f, 1.f, 0.f, 0.f);

	XMStoreFloat4x4(
		&_View,
		XMMatrixLookToLH(
			XMLoadFloat4(&EyePos),
			XMLoadFloat4(&EyeDir),
			XMLoadFloat4(&UpDir)
		)
	);
}

void Camera::GetViewMatrix(Matrix4x4& ViewMatrix) const
{
	memcpy(&ViewMatrix, &_View, sizeof(Matrix4x4));
}

void Camera::GetProjectionMatrix(Matrix4x4& ProjectionMatrix) const
{
	XMMATRIX ProjMatrix = XMMatrixTranspose(XMLoadFloat4x4(&_Proj));
	XMStoreFloat4x4(&ProjectionMatrix, ProjMatrix);
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
