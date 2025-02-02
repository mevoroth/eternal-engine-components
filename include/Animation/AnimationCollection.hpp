#pragma once

#include "Animation/Animation.hpp"
#include "Animation/AnimationDefines.hpp"
#include "Animation/AnimationState.hpp"
#include "Container/StableVector.hpp"

namespace Eternal
{
	namespace Components
	{
		using namespace Eternal::Container;

		template<typename AnimationStatePropertyType>
		struct AnimationCollection
		{
			StableVector<AnimationState<AnimationStatePropertyType>>	AnimationProperties;
			vector<uint32_t>											AnimationCompleted;
			Animation*													AnimationData = nullptr;

			void EvaluateCollection(_In_ float InDeltaSeconds)
			{
				for (auto AnimationPropertyIterator = AnimationProperties.Begin(); AnimationPropertyIterator != AnimationProperties.End(); ++AnimationPropertyIterator)
				{
					AnimationState<AnimationStatePropertyType>& CurrentProperty = *AnimationPropertyIterator;

					if (CurrentProperty.AnimationPlayback != AnimationPlaybackState::ANIMATIONPLAYBACKSTATE_STOP)
					{
						float AnimationTimeDilation = [AnimationPlayback = CurrentProperty.AnimationPlayback]()
						{
							float TimeDilation = AnimationDefines::TimeDilationDefault;
							switch (AnimationPlayback)
							{
							case AnimationPlaybackState::ANIMATIONPLAYBACKSTATE_PAUSE:
								TimeDilation = AnimationDefines::TimeDilationPause;
								break;

							case AnimationPlaybackState::ANIMATIONPLAYBACKSTATE_PLAY:
							default:
								break;
							}
							return TimeDilation;
						}();

						CurrentProperty.AnimationCurrentTime += InDeltaSeconds * AnimationTimeDilation;
						AnimationData->BindProperty(*CurrentProperty.AnimationProperty);
						AnimationData->EvaluateAnimation(CurrentProperty.AnimationCurrentTime);

						if (CurrentProperty.AnimationCurrentTime >= AnimationDefines::TimelineEnd)
						{
							AnimationCompleted.push_back(AnimationPropertyIterator.GetIndex());
						}
					}
				}
				AnimationData->UnbindProperty<AnimationStatePropertyType>();

				for (uint32_t AnimationCompletedIndex = 0; AnimationCompletedIndex < AnimationCompleted.size(); ++AnimationCompletedIndex)
				{
					uint32_t CompletedPropertyIndex = AnimationCompleted[AnimationCompletedIndex];
					const vector<AnimationOnCompleteFunctor>& CurrentAnimationOnCompleteFunctions = AnimationProperties[CompletedPropertyIndex].AnimationOnCompleteFunctions;
					for (uint32_t FunctionIndex = 0; FunctionIndex < CurrentAnimationOnCompleteFunctions.size(); ++FunctionIndex)
						CurrentAnimationOnCompleteFunctions[FunctionIndex]();
					AnimationProperties.Erase(CompletedPropertyIndex);
				}
				AnimationCompleted.clear();
			}
		};
	}
}
