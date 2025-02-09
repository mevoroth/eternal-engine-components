#pragma once

#include <functional>

namespace Eternal
{
	namespace Components
	{
		namespace AnimationDefines
		{
			static constexpr float TimelineBegin		= 0.0f;
			static constexpr float TimelineEnd			= 1.0f;
			static constexpr float TimeDilationDefault	= 1.0f;
			static constexpr float TimeDilationPause	= 0.0f;
		}

		class Animation;

		using AnimationBindFunctor			= void (*)(_In_ void* InProperty, _Inout_ Animation& InOutAnimation);
		using AnimationOnCompleteFunctor	= std::function<void()>;
		using AnimationCompositeType		= void;
	}
}
