#include "Light/Light.hpp"
#include "Transform/Transform.hpp"

namespace Eternal
{
	namespace Components
	{
		const Vector3& Light::GetColor() const
		{
			return _Color;
		}

		float Light::GetDistance() const
		{
			return _Distance;
		}

		float Light::GetIntensity() const
		{
			return _Intensity;
		}

		void Light::SetColor(_In_ const Vector3& InColor)
		{
			_Color = InColor;
		}

		void Light::SetIntensity(_In_ float InIntensity)
		{
			ETERNAL_ASSERT(InIntensity > 0.f);
			_Intensity = InIntensity;
		}

		void Light::SetDistance(_In_ float InDistance)
		{
			ETERNAL_ASSERT(InDistance > 0.f);
			_Distance = InDistance;
		}

		void Light::UpdateWorldToView(_In_ const Transform& InTransform)
		{
			Transform TransformNoTranslation = InTransform;
			TransformNoTranslation.SetTranslation(Vector3::Zero);

			Vector4 Direction = TransformNoTranslation.GetLocalToWorld() * Vector4::ForwardPosition;

			_Position = InTransform.GetTranslation();
			_Direction = Vector3(
				Direction.x,
				Direction.y,
				Direction.z
			);
		}
	}
}
