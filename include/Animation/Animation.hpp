#pragma once

#include "Animation/AnimationTimeline.hpp"
#include <string>
#include <variant>

namespace Eternal
{
	namespace Components
	{
		using namespace std;

		using AnimationTimelineVariants = variant<
			AnimationTimeline<float>,
			AnimationTimeline<Eternal::Types::Vector2>,
			AnimationTimeline<Eternal::Types::Vector3>,
			AnimationTimeline<Eternal::Types::Vector4>
		>;

		class Transform;

		class Animation
		{
		public:

			Animation(_In_ const string& InName)
				:
#if ETERNAL_DEBUG
				_Name(InName)
#endif
			{
			}

			template<typename AnimationType>
			Animation(_In_ const string& InName, _In_ AnimationType& InProperty)
				: Animation(InName)
			{
				InitializeTimeline<AnimationType>();
				BindProperty(InProperty);
			}

			void SetAnimationLength(_In_ float InAnimationLengthSeconds);
			float GetAnimationLength() const;
			void ReserveTimelines(_In_ uint32_t InTimelinesCount);

			template<typename AnimationKeyFrameValueType>
			AnimationTimeline<AnimationKeyFrameValueType>& AddTimeline(_In_ const string& InName)
			{
				_AnimationTimelines.push_back(AnimationTimeline<AnimationKeyFrameValueType>(InName));
				return get<AnimationTimeline<AnimationKeyFrameValueType>>(_AnimationTimelines.back());
			}

			template<typename AnimationType>
			void InitializeTimeline()
			{
				ReserveTimelines(1);
				string TimelineName = string(typeid(AnimationType).name()) + "Timeline";
				AddTimeline<AnimationType>(TimelineName);
			}

			template<typename AnimationKeyFrameValueType>
			AnimationTimeline<AnimationKeyFrameValueType>& GetTimeline(_In_ uint32_t InIndex)
			{
				return get<AnimationTimeline<AnimationKeyFrameValueType>>(_AnimationTimelines[InIndex]);
			}

			template<typename AnimationKeyFrameValueType>
			const AnimationTimeline<AnimationKeyFrameValueType>& GetTimeline(_In_ uint32_t InIndex) const
			{
				return get<const AnimationTimeline<AnimationKeyFrameValueType>>(_AnimationTimelines[InIndex]);
			}

			template<typename AnimationType>
			void BindProperty(_In_ AnimationType& InProperty)
			{
				ETERNAL_ASSERT(_AnimationTimelines.size() == 1);
				get<AnimationTimeline<AnimationType>>(_AnimationTimelines[0]).BindProperty(InProperty);
			}
			
			template<typename AnimationType>
			void UnbindProperty()
			{
				ETERNAL_ASSERT(_AnimationTimelines.size() == 1);
				get<AnimationTimeline<AnimationType>>(_AnimationTimelines[0]).UnbindProperty();
			}

			void EvaluateAnimation(_In_ float InKeyTime)
			{
				for (uint32_t TimelineIndex = 0; TimelineIndex < _AnimationTimelines.size(); ++TimelineIndex)
				{
					visit(
						[InKeyTime](auto& InOutTimeline)
						{
							InOutTimeline.EvaluateTimeline(InKeyTime);
						},
						_AnimationTimelines[TimelineIndex]
					);
				}
			}

		private:

#if ETERNAL_DEBUG
			string								_Name;
#endif
			vector<AnimationTimelineVariants>	_AnimationTimelines;
			float								_AnimationLengthSeconds = 0.0f;

		};

		template<> void Animation::InitializeTimeline<Eternal::Components::Transform>();
		template<> void Animation::BindProperty(_In_ Eternal::Components::Transform& InTransformProperty);
		template<> void Animation::UnbindProperty<Eternal::Components::Transform>();
	}
}
