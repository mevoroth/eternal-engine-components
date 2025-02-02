#pragma once

namespace Eternal
{
	namespace Components
	{
		enum class AnimationPlaybackState
		{
			ANIMATIONPLAYBACKSTATE_STOP = 0,
			ANIMATIONPLAYBACKSTATE_PLAY,
			ANIMATIONPLAYBACKSTATE_PAUSE
		};

		template<typename AnimationStatePropertyType>
		struct AnimationState
		{
			AnimationPlaybackState		AnimationPlayback		= AnimationPlaybackState::ANIMATIONPLAYBACKSTATE_STOP;
			float						AnimationCurrentTime	= 0.0f;
			AnimationStatePropertyType*	AnimationProperty		= nullptr;
		};
	}
}
