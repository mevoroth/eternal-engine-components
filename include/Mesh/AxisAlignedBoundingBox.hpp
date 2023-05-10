#pragma once

#include "Types/Types.hpp"

namespace Eternal
{
	namespace Components
	{
		using namespace Eternal::Types;

		class AxisAlignedBoundingBox
		{
		public:
			const Vector3& GetMin() const;
			const Vector3& GetMax() const;
			void SetMin(_In_ const Vector3& InMin);
			void SetMax(_In_ const Vector3& InMax);
			void Extend(_In_ const Vector3& InPosition);

		private:
			Vector3 _Min = Vector3::PositiveInfinity;
			Vector3 _Max = Vector3::NegativeInfinity;
		};
	}
}
