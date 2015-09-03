#include "Transform/Transform.hpp"

#include <DirectXMath.h>

using namespace Eternal::Components;

Transform::Transform()
	: Translation(0.f, 0.f, 0.f)
	, Scaling(1.f, 1.f, 1.f)
{
	XMStoreFloat4(&Rotation, XMQuaternionIdentity());
}

void Transform::SetTranslation(const Vector3& D)
{
	Translation = D;
}
void Transform::SetRotation(const Vector4& R)
{
	Rotation = R;
}
void Transform::SetScaling(const Vector3& S)
{
	Scaling = S;
}
void Transform::Translate(const Vector3& D)
{
	Translation += (Vector3)Vector3(D.x, D.y, D.z);
}
void Transform::Rotate(const Vector4& R)
{
	XMVECTOR NewRotation = XMQuaternionMultiply(
		XMLoadFloat4(&Rotation),
		XMLoadFloat4(&R)
	);
	XMStoreFloat4(&Rotation, NewRotation);
}
void Transform::Rotate(const Vector3& R)
{
	XMVECTOR NewRotation = XMQuaternionMultiply(
		XMLoadFloat4(&Rotation),
		XMQuaternionRotationRollPitchYaw(R.x, R.y, R.z)
	);
	XMStoreFloat4(&Rotation, NewRotation);
}
void Transform::Scale(const Vector3& S)
{
	Scaling *= S;
}
Transform Transform::GetAbsolute(const Transform& Relative) const
{
	return *this; // TODO: WRONG
}
Matrix4x4 Transform::GetModelMatrix() const
{
	XMMATRIX ModelMatrix = XMMatrixScalingFromVector(XMLoadFloat3(&Scaling))
		* XMMatrixRotationQuaternion(XMLoadFloat4(&Rotation))
		* XMMatrixTranslationFromVector(XMLoadFloat3(&Translation));
	Matrix4x4 ReturnMatrix;
	XMStoreFloat4x4(&ReturnMatrix, ModelMatrix);
	return ReturnMatrix;
}
Vector3 Transform::GetRight() const
{
	Matrix4x4 ModelMatrix = GetModelMatrix();
	return Vector3(ModelMatrix(0, 0), ModelMatrix(0, 1), ModelMatrix(0, 2));
}
Vector3 Transform::GetUp() const
{
	Matrix4x4 ModelMatrix = GetModelMatrix();
	return Vector3(ModelMatrix(1, 0), ModelMatrix(1, 1), ModelMatrix(1, 2));
}
Vector3 Transform::GetForward() const
{
	Matrix4x4 ModelMatrix = GetModelMatrix();
	return Vector3(ModelMatrix(2, 0), ModelMatrix(2, 1), ModelMatrix(2, 2));
}
