#pragma once

#include "Animation/Animation.hpp"

namespace Eternal
{
	namespace Components
	{
		using namespace std;

		template<typename AnimationStatePropertyType>
		struct AnimationCollection
		{
			vector<AnimationState<AnimationStatePropertyType>>	AnimationProperties;
			Animation*											AnimationData = nullptr;

			void EvaluateCollection(_In_ float InDeltaSeconds)
			{
				for (uint32_t PropertyIndex = 0; PropertyIndex < AnimationProperties.size(); ++PropertyIndex)
				{
					if (AnimationProperties[PropertyIndex].AnimationPlayback != AnimationPlaybackState::ANIMATIONPLAYBACKSTATE_STOP)
					{
						float AnimationTimeDilation = [AnimationPlayback = AnimationProperties[PropertyIndex].AnimationPlayback]()
						{
							float TimeDilation = 1.0f;
							switch (AnimationPlayback)
							{
							case AnimationPlaybackState::ANIMATIONPLAYBACKSTATE_PAUSE:
								TimeDilation = 0.0f;
								break;

							case AnimationPlaybackState::ANIMATIONPLAYBACKSTATE_PLAY:
							default:
								break;
							}
							return TimeDilation;
						}();

						AnimationProperties[PropertyIndex].AnimationCurrentTime += InDeltaSeconds * AnimationTimeDilation;
						AnimationData->BindProperty(*AnimationProperties[PropertyIndex].AnimationProperty);
						AnimationData->EvaluateAnimation(AnimationProperties[PropertyIndex].AnimationCurrentTime);
					}
				}
				AnimationData->UnbindProperty<AnimationStatePropertyType>();
			}
		};
	}
}
