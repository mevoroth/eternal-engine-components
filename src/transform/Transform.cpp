#include "Transform/Transform.hpp"

using namespace Eternal::Components;

Transform::Transform()
	: Translation(NewVector4(0.f, 0.f, 0.f, 0.f))
	, Rotation(XMQuaternionIdentity())
	, Scaling(NewVector4(1.f, 1.f, 1.f, 0.f))
{
}

void Transform::Translate(const Vector3& d)
{
	Translation = XMVectorAdd(Translation, XMLoadFloat3(&d));
}
void Transform::Rotate(const Vector4& r)
{
	Rotation = XMQuaternionMultiply(Rotation, r);
}
void Transform::Rotate(const Vector3& r)
{
	Rotation = XMQuaternionMultiply(Rotation, XMQuaternionRotationRollPitchYaw(r.x, r.y, r.z));
}
void Transform::Scale(const Vector3& s)
{
	Scaling = XMVectorMultiply(Scaling, XMLoadFloat3(&s));
}
Transform Transform::GetAbsolute(const Transform& Relative) const
{
	return *this; // TODO: WRONG
}
Matrix4x4 Transform::GetModelMatrix() const
{
	return XMMatrixScalingFromVector(Scaling)
		* XMMatrixRotationQuaternion(Rotation)
		* XMMatrixTranslationFromVector(Translation);
}
