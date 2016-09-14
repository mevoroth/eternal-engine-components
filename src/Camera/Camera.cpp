#include "Camera/Camera.hpp"

#include <string>

using namespace Eternal::Components;

Camera::Camera(_In_ float Near, _In_ float Far)
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

void Camera::GetViewMatrix(_Out_ Matrix4x4& ViewMatrix) const
{
	ViewMatrix = _View;
}

void Camera::GetProjectionMatrix(_Out_ Matrix4x4& ProjectionMatrix) const
{
	ProjectionMatrix = _Proj;
}

void Camera::GetViewProjectionMatrix(_Out_ Matrix4x4& ViewProjectionMatrix) const
{
	ViewProjectionMatrix = _View * _Proj;
}

void Camera::SetNear(_In_ float Near)
{
	_Near = Near;
	_UpdateMatrix();
}
void Camera::SetFar(_In_ float Far)
{
	_Far = Far;
	_UpdateMatrix();
}
