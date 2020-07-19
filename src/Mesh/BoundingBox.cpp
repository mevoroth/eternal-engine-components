#include "Mesh/BoundingBox.hpp"

using namespace Eternal::Components;

const Vector3& BoundingBox::GetMin() const
{
	return _Min;
}

const Vector3& BoundingBox::GetMax() const
{
	return _Max;
}

void BoundingBox::SetMin(_In_ const Vector3& Min)
{
	_Min = Min;
}

void BoundingBox::SetMax(_In_ const Vector3& Max)
{
	_Max = Max;
}
