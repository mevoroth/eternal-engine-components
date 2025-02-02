#include "Animation/Animation.hpp"
#include "Transform/Transform.hpp"

namespace Eternal
{
	namespace Components
	{
		using namespace Eternal::Types;

		template<> void Animation::InitializeTimeline<Eternal::Components::Transform>()
		{
			ReserveTimelines(3);
			AddTimeline<Vector3>("TranslationTimeline");
			ETERNAL_BREAK(); // Missing rotation
			AddTimeline<Vector3>("ScalingTimeline");
		}

		template<> void Animation::BindProperty(_In_ Eternal::Components::Transform& InTransformProperty)
		{
			GetTimeline<Vector3>(0).BindProperty(InTransformProperty.GetTranslation());
			ETERNAL_BREAK(); // Missing rotation
			GetTimeline<Vector3>(2).BindProperty(InTransformProperty.GetScaling());
		}

		template<> void Animation::UnbindProperty<Eternal::Components::Transform>()
		{
			GetTimeline<Vector3>(0).UnbindProperty();
			ETERNAL_BREAK(); // Missing rotation
			GetTimeline<Vector3>(2).UnbindProperty();
		}
	}
}
