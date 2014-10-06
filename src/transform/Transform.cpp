#include "Transform.hpp"

using namespace Eternal::Components;

void Transform::Translate(const Vector3& d)
{
	Translation = XMVectorAdd(Translation, XMLoadFloat3(&d));
}
void Transform::Rotate(const Vector4& r)
{
	Rotation = XMQuaternionMultiply(Rotation, r);
}
void Transform::Scale(const Vector3& s)
{
	Scaling = XMVectorMultiply(Scaling, XMLoadFloat3(&s));
}
Matrix4x4 Transform::GetModelMatrix() const
{
	return XMMatrixScalingFromVector(Scaling)
		* XMMatrixRotationQuaternion(Rotation)
		* XMMatrixTranslationFromVector(Translation);
}
