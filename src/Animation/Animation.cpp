#include "Animation/Animation.hpp"

#include "Animation/AnimationTimeline.hpp"

namespace Eternal
{
	namespace Components
	{
		void Animation::SetAnimationLength(_In_ float InAnimationLengthSeconds)
		{
			_AnimationLengthSeconds = InAnimationLengthSeconds;
		}

		float Animation::GetAnimationLength() const
		{
			return _AnimationLengthSeconds;
		}

		void Animation::ReserveTimelines(_In_ uint32_t InTimelinesCount)
		{
			_AnimationTimelines.reserve(InTimelinesCount);
		}
	}
}
