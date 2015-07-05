#ifndef _LIGHTS_HPP_
#define _LIGHTS_HPP_

#include "ComponentsSettings.hpp"
#include "Types/Types.hpp"

namespace Eternal
{
	namespace Components
	{
		using namespace Types;
		class Light
		{
		public:
			Light(const Vector3& Position, float Distance);
		private:
			Vector3 _Position;
			// 0: infinite
			// > 0: distance
			float _Distance;
		};
	}
}

#endif
