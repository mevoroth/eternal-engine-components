#include "Transform/Transform.hpp"

#include <DirectXMath.h>

using namespace Eternal::Components;

Transform::Transform()
	: Translation(0.f, 0.f, 0.f, 0.f)
	, Scaling(1.f, 1.f, 1.f, 0.f)
{
	XMStoreFloat4(&Rotation, XMQuaternionIdentity());
}

void Transform::Translate(const Vector3& D)
{
	//Translation += Vector4(D.x, D.y, D.z, 0.f);
	Translation = Vector4(D.x + Translation.x, D.y + Translation.y, D.z + Translation.z,  + Translation.w);
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
void Transform::Scale(const Vector3& s)
{
	XMVECTOR NewScaling = XMVectorMultiply(XMLoadFloat4(&Scaling), XMLoadFloat3(&s));
	XMStoreFloat4(&Scaling, NewScaling);
}
Transform Transform::GetAbsolute(const Transform& Relative) const
{
	return *this; // TODO: WRONG
}
Matrix4x4 Transform::GetModelMatrix() const
{
	XMMATRIX ModelMatrix = XMMatrixScalingFromVector(XMLoadFloat4(&Scaling))
		* XMMatrixRotationQuaternion(XMLoadFloat4(&Rotation))
		* XMMatrixTranslationFromVector(XMLoadFloat4(&Translation));
	Matrix4x4 ReturnMatrix;
	XMStoreFloat4x4(&ReturnMatrix, ModelMatrix);
	return ReturnMatrix;
}
