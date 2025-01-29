#pragma once

#include "Animation/AnimationTimeline.hpp"
#include <string>

namespace Eternal
{
	namespace Components
	{
		using namespace std;

		class AnimationTimelineBase;
		template<typename AnimationKeyFrameValueType>
		class AnimationTimeline;

		class Animation
		{
		public:

			Animation(_In_ const string& InName);

			void ReserveTimelines(_In_ uint32_t InTimelinesCount);
			template<typename AnimationKeyFrameValueType>
			AnimationTimeline<AnimationKeyFrameValueType>* AddTimeline(_In_ const string& InName)
			{
				AnimationTimeline<AnimationKeyFrameValueType>* Timeline = new AnimationTimeline<AnimationKeyFrameValueType>(InName);
				_AnimationTimelines.push_back(Timeline);
				return Timeline;
			}

		private:

#if ETERNAL_DEBUG
			string							_Name;
#endif
			vector<AnimationTimelineBase*>	_AnimationTimelines;

		};
	}
}
