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
			Vector3& GetPosition() { return _Position; }
		private:
			Vector3 _Position = Vector3(0.f, 0.f, 0.f);
			Vector3 _Color = Vector3(1.f, 1.f, 1.f);
			// 0: infinite
			// > 0: distance
			float _Distance = 10.f;
			float _Intensity = 1.f;
		};
	}
}

#endif
