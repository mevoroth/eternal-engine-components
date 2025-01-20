#pragma once

namespace Eternal
{
	namespace Components
	{
		using PartitionMapping2DFunctor = uint32_t (*)(_In_ uint32_t InX, _In_ uint32_t InY, _In_ uint32_t InRowSize);

		uint32_t PartitionMapping2DToIndexLinear(_In_ uint32_t InX, _In_ uint32_t InY, _In_ uint32_t InRowSize);
		uint32_t PartitionMapping2DToIndexMorton(_In_ uint32_t InX, _In_ uint32_t InY, _In_ uint32_t InRowSize);
	}
}
