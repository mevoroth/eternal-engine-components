#include "Mesh/AxisAlignedBoundingBox.hpp"

using namespace Eternal::Components;

const Vector3& AxisAlignedBoundingBox::GetMin() const
{
	return _Min;
}

const Vector3& AxisAlignedBoundingBox::GetMax() const
{
	return _Max;
}

void AxisAlignedBoundingBox::SetMin(_In_ const Vector3& Min)
{
	_Min = Min;
}

void AxisAlignedBoundingBox::SetMax(_In_ const Vector3& Max)
{
	_Max = Max;
}
