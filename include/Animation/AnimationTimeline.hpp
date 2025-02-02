#pragma once

#include "Animation/AnimationKeyFrame.hpp"
#include "Math/Math.hpp"
#include <string>

namespace Eternal
{
	namespace Components
	{
		using namespace std;

		template<typename AnimationKeyFrameValueType>
		class AnimationTimeline
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

			void ReserveKeys(_In_ uint32_t InKeysCount)
			{
				_Timeline.reserve(InKeysCount);
			}

			void AddKeyFrame(_In_ const AnimationKeyFrame<AnimationKeyFrameValueType>& InKeyFrame)
			{
				_Timeline.insert(_FindNearest(InKeyFrame.AnimationKeyTime), InKeyFrame);
			}

			void BindProperty(_In_ AnimationKeyFrameValueType& InProperty)
			{
				_BoundProperty = &InProperty;
			}

			void UnbindProperty()
			{
				_BoundProperty = nullptr;
			}

			AnimationKeyFrameValueType& AddKey(_In_ float InKeyTime)
			{
				return _Timeline.insert(_FindNearest(InKeyTime), { InKeyTime, AnimationKeyFrameValueType() })->AnimationKeyValue;
			}

			AnimationKeyFrameValueType EvaluateTimelineValue(_In_ float InKeyTime)
			{
				auto KeyFrameNext = upper_bound(
					_Timeline.begin(),
					_Timeline.end(),
					InKeyTime,
					[](_In_ float InKeyTime, _In_ const AnimationKeyFrame<AnimationKeyFrameValueType>& InKeyFrame)
					{
						return InKeyTime < InKeyFrame.AnimationKeyTime;
					}
				);

				if (KeyFrameNext == _Timeline.begin())
					return _Timeline.front().AnimationKeyValue;

				if (KeyFrameNext == _Timeline.end())
					return _Timeline.back().AnimationKeyValue;

				auto KeyFramePrevious = KeyFrameNext - 1;
				float Alpha = (InKeyTime - KeyFramePrevious->AnimationKeyTime) / (KeyFrameNext->AnimationKeyTime - KeyFramePrevious->AnimationKeyTime);
				return Eternal::Math::Lerp<AnimationKeyFrameValueType>(KeyFramePrevious->AnimationKeyValue, KeyFrameNext->AnimationKeyValue, Alpha);
			}

			void EvaluateTimeline(_In_ float InKeyTime)
			{
				ETERNAL_ASSERT(_BoundProperty);
				*_BoundProperty = EvaluateTimelineValue(InKeyTime);
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
			string						_Name;
#endif
			TimelineVector				_Timeline;
			AnimationKeyFrameValueType*	_BoundProperty = nullptr;

		};
	}
}
