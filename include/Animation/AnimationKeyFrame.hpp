#pragma once

namespace Eternal
{
	namespace Components
	{
		struct AnimationKeyFrameBase
		{
			float AnimationKeyTime = 0.0f;
		};

		template<typename AnimationKeyFrameValueType>
		struct AnimationKeyFrame : public AnimationKeyFrameBase
		{
			AnimationKeyFrameValueType AnimationKeyValue = AnimationKeyFrameValueType(0);
		};
	}
}
