#pragma once

#include "ComponentsSettings.hpp"
#include "Types/Types.hpp"
#include "Light/Shadow.hpp"

namespace Eternal
{
	namespace Components
	{
		using namespace Types;
		
		class Transform;

		enum class LightType : uint32_t
		{
			LIGHT_TYPE_DIRECTIONAL = 0,
			LIGHT_TYPE_POINT,
			LIGHT_TYPE_SPOTLIGHT,
			LIGHT_TYPE_AREA,
			LIGHT_TYPE_INVALID = ~0u
		};

		class Light
		{
		public:

			virtual void UpdateWorldToView(_In_ const Transform& InTransform);
			void SetDistance(_In_ float InDistance);
			void SetIntensity(_In_ float InIntensity);
			void SetColor(_In_ const Vector3& InColor);

			inline const Vector3& GetPosition() const { return _Position; }
			inline const Vector3& GetDirection() const { return _Direction; }
			const Vector3& GetColor() const;
			float GetDistance() const;
			float GetIntensity() const;

			inline const Shadow& GetShadow() const { return _Shadow; }
			inline const LightType& GetLightType() const { return _LightType; }

		protected:
			Shadow _Shadow;
			Vector3 _Position		= Vector3::Zero;
			float _Distance			= 10.f;
			Vector3 _Direction		= Vector3::Down;
			float _Intensity		= 1.f;
			Vector3 _Color			= Vector3(1.f, 1.f, 1.f);
			LightType _LightType	= LightType::LIGHT_TYPE_INVALID;
		};
	}
}
