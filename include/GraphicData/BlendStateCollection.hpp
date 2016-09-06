#ifndef _BLEND_STATE_COLLECTION_HPP_
#define _BLEND_STATE_COLLECTION_HPP_

namespace Eternal
{
	namespace Graphics
	{
		class BlendState;
	}

	namespace GraphicData
	{
		using namespace Eternal::Graphics;

		class BlendStateCollection
		{
		public:
			enum BlendStateKey
			{
				SOURCE = 0,
				ALPHA,
				ADDITIVE,
				BLENDSTATE_COUNT
			};

			BlendStateCollection();
			~BlendStateCollection();

			BlendState* GetBlendState(_In_ const BlendStateKey& Key);

		private:
			BlendState* _BlendStates[BLENDSTATE_COUNT];
		};
	}
}

#endif
