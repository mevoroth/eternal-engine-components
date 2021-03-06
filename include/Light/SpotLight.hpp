#ifndef _SPOT_LIGHT_HPP_
#define _SPOT_LIGHT_HPP_

#include "Types/Types.hpp"
#include "Light/Light.hpp"
#include "Light/Shadow.hpp"

namespace Eternal
{
	namespace Components
	{
		using namespace Eternal::Types;

		class SpotLight : public Light
		{
		public:
			SpotLight(_In_ float FOV, _In_ const Vector3& Color, _In_ float Distance, _In_ float Intensity);

			void SetFOV(_In_ float FOV);

		private:
			float _FOV = 0.78539816339f; // 45�
		};
	}
}

#endif
