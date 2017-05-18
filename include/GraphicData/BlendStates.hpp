#ifndef _BLEND_STATES_HPP_
#define _BLEND_STATES_HPP_

#include "GraphicData/StaticCollection.hpp"

namespace Eternal
{
	namespace Graphics
	{
		class BlendState;
	}

	namespace GraphicData
	{
		enum BlendStateKey
		{
			BLEND_STATE_SOURCE = 0,
			BLEND_STATE_ALPHA,
			BLEND_STATE_ADDITIVE,
			BLEND_STATE_COUNT
		};

		class BlendStates : public StaticCollection<BlendStateKey, BlendState, BLEND_STATE_COUNT>
		{
		public:
			void Initialize(_In_ Device& DeviceObj) override;
		};
	}
}

#endif
