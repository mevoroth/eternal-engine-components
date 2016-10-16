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
			Light(_In_ const Vector3& Color, _In_ float Distance, _In_ float Intensity);

			void SetDistance(_In_ float Distance);
			void SetIntensity(_In_ float Intensity);
			void SetColor(_In_ const Vector3& Color);

			const Vector3& GetColor() const;
			float GetDistance() const;
			float GetIntensity() const;

		private:
			Vector3 _Color = Vector3(1.f, 1.f, 1.f);
			float _Distance = 10.f;
			float _Intensity = 1.f;
		};
	}
}

#endif
