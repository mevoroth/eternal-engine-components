#pragma once

#include "Animation/AnimationDefines.hpp"
#include <functional>

namespace Eternal
{
	namespace Components
	{
		using namespace std;

		enum class AnimationPlaybackState
		{
			ANIMATIONPLAYBACKSTATE_STOP = 0,
			ANIMATIONPLAYBACKSTATE_PLAY,
			ANIMATIONPLAYBACKSTATE_PAUSE
		};

		template<typename AnimationStatePropertyType>
		struct AnimationState
		{
			AnimationPlaybackState				AnimationPlayback				= AnimationPlaybackState::ANIMATIONPLAYBACKSTATE_STOP;
			float								AnimationCurrentTime			= AnimationDefines::TimelineBegin;
			AnimationStatePropertyType*			AnimationProperty				= nullptr;
			vector<AnimationOnCompleteFunctor>	AnimationOnCompleteFunctions;
		};
	}
}
