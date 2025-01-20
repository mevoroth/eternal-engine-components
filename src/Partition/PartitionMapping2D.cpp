#include "Partition/PartitionMapping2D.hpp"

namespace Eternal
{
	namespace Components
	{
		static constexpr uint32_t PartitionMapping2DRowMax = 256;

		uint32_t PartitionMapping2DToIndexLinear(_In_ uint32_t InX, _In_ uint32_t InY, _In_ uint32_t InRowSize)
		{
			ETERNAL_ASSERT(InX < PartitionMapping2DRowMax && "InX cannot be above 255");
			ETERNAL_ASSERT(InY < PartitionMapping2DRowMax && "InY cannot be above 255");
			ETERNAL_ASSERT(InRowSize <= PartitionMapping2DRowMax && "Partition cannot be above 256");

			return InY * InRowSize + InX;
		}

		uint32_t PartitionMapping2DToIndexMorton(_In_ uint32_t InX, _In_ uint32_t InY, _In_ uint32_t InRowSize)
		{
			ETERNAL_ASSERT(InX < PartitionMapping2DRowMax && "InX cannot be above 255");
			ETERNAL_ASSERT(InY < PartitionMapping2DRowMax && "InY cannot be above 255");
			ETERNAL_ASSERT(InRowSize <= PartitionMapping2DRowMax && "Partition cannot be above 256");

			return static_cast<uint32_t>(((InX * 0x0101010101010101ULL & 0x8040201008040201ULL) * 0x0102040810204081ULL >> 49) & 0x5555
									|	 ((InY * 0x0101010101010101ULL & 0x8040201008040201ULL) * 0x0102040810204081ULL >> 48) & 0xAAAA);
		}
	}
}
