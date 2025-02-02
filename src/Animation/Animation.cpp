#include "Animation/Animation.hpp"

#include "Animation/AnimationTimeline.hpp"

namespace Eternal
{
	namespace Components
	{
		void Animation::ReserveTimelines(_In_ uint32_t InTimelinesCount)
		{
			_AnimationTimelines.reserve(InTimelinesCount);
		}
	}
}
