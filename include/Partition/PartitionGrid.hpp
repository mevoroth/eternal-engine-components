#pragma once

#include "Types/Types.hpp"
#include "Partition/PartitionMapping2D.hpp"
#include <array>

namespace Eternal
{
	namespace Components
	{
		using namespace Types;

		template<typename PartitionType, uint32_t PartitionGridSize, PartitionMapping2DFunctor PartitionMapping2DFunction>
		class PartitionGrid
		{
		public:

			static constexpr int PartitionsCount = PartitionGridSize * PartitionGridSize;
			static constexpr float PartitionGridSizeFloat = static_cast<float>(PartitionGridSize);

			ETERNAL_STATIC_ASSERT(PartitionGridSize > 0, "Grid size needs to be bigger than 0");

			PartitionGrid(_In_ const Vector2& InBoundsMin, _In_ const Vector2& InBoundsMax)
			{
				Vector2 BoundsSize = InBoundsMax - InBoundsMin;

				_WorldToPartitionMul = Vector2(
					PartitionGridSizeFloat / BoundsSize.x,
					PartitionGridSizeFloat / BoundsSize.y
				);

				_WorldToPartitionAdd = Vector2(
					-InBoundsMin.x * PartitionGridSizeFloat / BoundsSize.x,
					-InBoundsMin.y * PartitionGridSizeFloat / BoundsSize.y
				);
			}

			PartitionType& GetPartition(_In_ const Vector2& InPosition)
			{
				uint32_t GridX = 0u;
				uint32_t GridY = 0u;

				_GetPartitionPosition(InPosition, GridX, GridY);

				return _Grid[PartitionMapping2DFunction(GridX, GridY, PartitionGridSize)];
			}

			PartitionType& GetPartition(_In_ const Vector3& InPosition)
			{
				Vector2 Position2D(InPosition.x, InPosition.y);
				return GetPartition(Position2D);
			}

		private:

			void _GetPartitionPosition(_In_ const Vector2& InPosition2D, _Out_ uint32_t& OutX, _Out_ uint32_t& OutY)
			{
				Vector2 PartitionXY = InPosition2D * _WorldToPartitionMul + _WorldToPartitionAdd;
				PartitionXY.x = Math::Clamp(PartitionXY.x, 0.0f, PartitionGridSizeFloat - 1.0f);
				PartitionXY.y = Math::Clamp(PartitionXY.y, 0.0f, PartitionGridSizeFloat - 1.0f);

				OutX = static_cast<uint32_t>(PartitionXY.x);
				OutY = static_cast<uint32_t>(PartitionXY.y);
			}

			array<PartitionType, PartitionsCount> _Grid;
			Vector2 _WorldToPartitionMul = Vector2::Zero;
			Vector2 _WorldToPartitionAdd = Vector2::Zero;

		};
	}
}
