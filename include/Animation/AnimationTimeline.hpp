#pragma once

#include "Animation/AnimationKeyFrame.hpp"
#include <string>

namespace Eternal
{
	namespace Components
	{
		using namespace std;

		class AnimationTimelineBase
		{
		public:

			virtual void ReserveKeys(_In_ uint32_t InKeysCount) = 0;

		};

		template<typename AnimationKeyFrameValueType>
		class AnimationTimeline : public AnimationTimelineBase
		{
		public:

			using TimelineVector = vector<AnimationKeyFrame<AnimationKeyFrameValueType>>;
			using TimelineVectorIterator = typename TimelineVector::iterator;

			AnimationTimeline(_In_ const string& InName)
				:
#if ETERNAL_DEBUG
				_Name(InName)
#endif
			{
			}

			virtual void ReserveKeys(_In_ uint32_t InKeysCount) override
			{
				_Timeline.reserve(InKeysCount);
			}

			void AddKeyFrame(_In_ const AnimationKeyFrame<AnimationKeyFrameValueType>& InKeyFrame)
			{
				_Timeline.insert(_FindNearest(InKeyFrame.AnimationKeyTime), InKeyFrame);
			}

			AnimationKeyFrameValueType& AddKey(_In_ float InKeyTime)
			{
				return _Timeline.insert(_FindNearest(InKeyTime), { InKeyTime, AnimationKeyFrameValueType() })->AnimationKeyValue;
			}

		private:

			TimelineVectorIterator _FindNearest(_In_ float InKeyTime)
			{
				if (_Timeline.size() == 0)
					return _Timeline.begin();

				auto TimelineIterator = _Timeline.rbegin();
				while (TimelineIterator != _Timeline.rend() && InKeyTime < TimelineIterator->AnimationKeyTime)
					++TimelineIterator;

				return TimelineIterator.base();
			}

#if ETERNAL_DEBUG
			string			_Name;
#endif
			TimelineVector	_Timeline;

		};
	}
}
