#include "Animation/Animation.hpp"

#include "Animation/AnimationTimeline.hpp"

namespace Eternal
{
	namespace Components
	{
		Animation::Animation(_In_ const string& InName)
			:
#if ETERNAL_DEBUG
			_Name(InName)
#endif
		{
		}

		void Animation::ReserveTimelines(_In_ uint32_t InTimelinesCount)
		{
			_AnimationTimelines.reserve(InTimelinesCount);
		}
	}
}
