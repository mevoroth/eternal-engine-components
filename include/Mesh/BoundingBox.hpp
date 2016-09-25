#ifndef _BOUNDING_BOX_HPP_
#define _BOUNDING_BOX_HPP_

#include "Types/Types.hpp"
#include "Mesh/Mesh.hpp"

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
			Vector3 _Min = Vector3(-1.f, -1.f, -1.f);
			Vector3 _Max = Vector3(1.f, 1.f, 1.f);
		};
	}
}

#endif
