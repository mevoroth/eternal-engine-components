#include "Mesh/AxisAlignedBoundingBox.hpp"

namespace Eternal
{
	namespace Components
	{
		const Vector3& AxisAlignedBoundingBox::GetMin() const
		{
			return _Min;
		}

		const Vector3& AxisAlignedBoundingBox::GetMax() const
		{
			return _Max;
		}

		void AxisAlignedBoundingBox::SetMin(_In_ const Vector3& InMin)
		{
			_Min = InMin;
		}

		void AxisAlignedBoundingBox::SetMax(_In_ const Vector3& InMax)
		{
			_Max = InMax;
		}

		void AxisAlignedBoundingBox::Extend(_In_ const Vector3& InPosition)
		{
			_Min = Min(_Min, InPosition);
			_Max = Max(_Max, InPosition);
		}
	}
}
