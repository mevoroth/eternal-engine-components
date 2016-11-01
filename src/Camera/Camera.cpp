#include "Camera/Camera.hpp"

#include <string>

using namespace Eternal::Components;

Camera::Camera(_In_ float Near, _In_ float Far)
	: _Near(Near)
	, _Far(Far)
{
	_UpdateViewMatrix();
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

void Camera::GetViewProjectionMatrixTransposed(_Out_ Matrix4x4& ViewProjectionMatrix) const
{
	GetViewProjectionMatrix(ViewProjectionMatrix);
	Transpose(ViewProjectionMatrix);
}

void Camera::GetViewProjectionMatrixInverse(_Out_ Matrix4x4& ViewProjectionInverse) const
{
	GetViewProjectionMatrix(ViewProjectionInverse);
	Inverse(ViewProjectionInverse);
}

void Camera::GetViewProjectionMatrixInverseTransposed(_Out_ Matrix4x4& ViewProjectionInverse) const
{
	GetViewProjectionMatrixInverse(ViewProjectionInverse);
	Transpose(ViewProjectionInverse);
}

void Camera::SetNear(_In_ float Near)
{
	_Near = Near;
	_UpdateProjectionMatrix();
}

void Camera::SetFar(_In_ float Far)
{
	_Far = Far;
	_UpdateProjectionMatrix();
}

const Vector3& Camera::GetPosition() const
{
	return _Position;
}

const Vector3& Camera::GetForward() const
{
	return _Forward;
}

const Vector3& Camera::GetRight() const
{
	return _Right;
}

const Vector3& Camera::GetUp() const
{
	return _Up;
}

void Camera::SetPosition(_In_ const Vector3& Position)
{
	_Position = Position;
	_UpdateViewMatrix();
}

void Camera::SetForward(_In_ const Vector3& Forward)
{
	_Forward = Forward;
	_UpdateViewMatrix();
}

void Camera::SetUp(_In_ const Vector3& Up)
{
	_Up = Up;
	_UpdateViewMatrix();
}

void Camera::UpdateViewMatrix(_In_ const Vector3& Position, _In_ const Vector3& Forward, _In_ const Vector3& Up)
{
	_Position = Position;
	_Forward = Normalize(Forward);
	_Up = Normalize(Up);
	_UpdateViewMatrix();
}

void Camera::_UpdateViewMatrix()
{
	_View = NewLookToLH(_Position, _Forward, _Up);
	_Right = Normalize(Cross(_Up, _Forward));
}
