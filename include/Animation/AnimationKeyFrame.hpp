#pragma once

namespace Eternal
{
	namespace Components
	{
		template<typename AnimationKeyFrameValueType>
		struct AnimationKeyFrame
		{
			float AnimationKeyTime							= 0.0f;
			AnimationKeyFrameValueType AnimationKeyValue	= AnimationKeyFrameValueType(0);
		};
	}
}
