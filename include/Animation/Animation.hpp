#pragma once

#include "Animation/AnimationDefines.hpp"
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
			void SetBindFunction(_In_ const AnimationBindFunctor& InBindFunction);
			AnimationBindFunctor GetBindFunction();
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
				if constexpr (is_same_v<decltype(InProperty), float&> ||
							  is_same_v<decltype(InProperty), Eternal::Types::Vector2&> ||
							  is_same_v<decltype(InProperty), Eternal::Types::Vector3&> ||
							  is_same_v<decltype(InProperty), Eternal::Types::Vector4&>)
				{
					ETERNAL_ASSERT(_AnimationTimelines.size() == 1);
					get<AnimationTimeline<AnimationType>>(_AnimationTimelines[0]).BindProperty(InProperty);
				}
				else
				{
					if (AnimationBindFunctor BindFunction = GetBindFunction())
					{
						BindFunction(&InProperty, *this);
						return;
					}
				}
			}
			
			template<typename AnimationType>
			void UnbindProperty()
			{
				if constexpr (is_same_v<AnimationType, float> ||
							  is_same_v<AnimationType, Eternal::Types::Vector2> ||
							  is_same_v<AnimationType, Eternal::Types::Vector3> ||
							  is_same_v<AnimationType, Eternal::Types::Vector4>)
				{
					ETERNAL_ASSERT(_AnimationTimelines.size() == 1);
					get<AnimationTimeline<AnimationType>>(_AnimationTimelines[0]).UnbindProperty();
				}
				else
				{
					for (uint32_t TimelineIndex = 0; TimelineIndex < _AnimationTimelines.size(); ++TimelineIndex)
					{
						visit(
							[](auto& InOutTimeline)
							{
								InOutTimeline.UnbindProperty();
							},
							_AnimationTimelines[TimelineIndex]
						);
					}
				}
			}

			void EvaluateAnimation(_In_ float InKeyTime);

		private:

#if ETERNAL_DEBUG
			string								_Name;
#endif
			vector<AnimationTimelineVariants>	_AnimationTimelines;
			AnimationBindFunctor				_AnimationBindFunction	= nullptr;
			float								_AnimationLengthSeconds	= 0.0f;

		};

		template<> void Animation::InitializeTimeline<Eternal::Components::Transform>();
		template<> void Animation::BindProperty(_In_ Eternal::Components::Transform& InTransformProperty);
		template<> void Animation::UnbindProperty<Eternal::Components::Transform>();
	}
}
