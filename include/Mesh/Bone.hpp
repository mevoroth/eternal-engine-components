#ifndef _BONE_HPP_
#define _BONE_HPP_

#include <cstdint>
#include <vector>

namespace Eternal
{
	namespace Components
	{
		using namespace std;

		class Bone
		{
		public:
			class IndexWeight
			{
			public:
				uint32_t Index;
				float Weight;
			};

			void PushInfluence(_In_ uint32_t Index, _In_ float Weight);

		private:
			vector<IndexWeight> _Influence;
		};
	}
}

#endif
