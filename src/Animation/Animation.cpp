#include "Animation/Animation.hpp"

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

		void Animation::SetBindFunction(_In_ const AnimationBindFunctor& InBindFunction)
		{
			_AnimationBindFunction = InBindFunction;
		}

		AnimationBindFunctor Animation::GetBindFunction()
		{
			return _AnimationBindFunction;
		}

		void Animation::ReserveTimelines(_In_ uint32_t InTimelinesCount)
		{
			_AnimationTimelines.reserve(InTimelinesCount);
		}

		void Animation::EvaluateAnimation(_In_ float InKeyTime)
		{
			for (uint32_t TimelineIndex = 0; TimelineIndex < _AnimationTimelines.size(); ++TimelineIndex)
			{
				visit(
					[InKeyTime](auto& InOutTimeline)
					{
						InOutTimeline.EvaluateTimeline(InKeyTime);
					},
					_AnimationTimelines[TimelineIndex]
				);
			}
		}
	}
}
