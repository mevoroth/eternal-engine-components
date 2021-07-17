#pragma once

#include "Types/Types.hpp"

namespace Eternal
{
	namespace Components
	{
		using namespace Eternal::Types;

		class BoundingBox
		{
		public:
			const Vector3& GetMin() const;
			const Vector3& GetMax() const;
			void SetMin(_In_ const Vector3& Min);
			void SetMax(_In_ const Vector3& Max);

		private:
			Vector3 _Min = -Vector3::One;
			Vector3 _Max = Vector3::One;
		};
	}
}
