#pragma once

#include "Types/Types.hpp"
#include "Types/AxisAlignedRectangle.hpp"
#include "Partition/PartitionMapping2D.hpp"
#include "Math/Math.hpp"
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
			static constexpr int GridSize = PartitionGridSize;
			static constexpr float PartitionGridSizeFloat = static_cast<float>(PartitionGridSize);

			ETERNAL_STATIC_ASSERT(PartitionGridSize > 0, "Grid size needs to be bigger than 0");

			PartitionGrid(_In_ const Vector2& InBoundsMin, _In_ const Vector2& InBoundsMax)
				: _WorldMinBounds(InBoundsMin)
				, _WorldMaxBounds(InBoundsMax)
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

			PartitionType& GetPartition(_In_ uint32_t InGridX, _In_ uint32_t InGridY)
			{
				return _Grid[PartitionMapping2DFunction(InGridX, InGridY, PartitionGridSize)];
			}

			PartitionType& GetPartition(_In_ const Vector2& InPosition)
			{
				uint32_t GridX = 0u;
				uint32_t GridY = 0u;

				_GetPartitionPosition(InPosition, GridX, GridY);

				return GetPartition(GridX, GridY);
			}

			PartitionType& GetPartition(_In_ const Vector3& InPosition)
			{
				Vector2 Position2D(InPosition.x, InPosition.y);
				return GetPartition(Position2D);
			}

			void GetPartitionsInBounds(_In_ const AxisAlignedRectangle& InBounds, _Out_ vector<PartitionType*>& OutPartitions)
			{
				if (InBounds.GetMaxBounds().x <= _WorldMinBounds.x || InBounds.GetMaxBounds().y <= _WorldMinBounds.y ||
					InBounds.GetMinBounds().x >= _WorldMaxBounds.x || InBounds.GetMinBounds().y >= _WorldMaxBounds.y)
					return;

				Vector2 BoundsMin = InBounds.GetMinBounds();
				Vector2 BoundsMax = InBounds.GetMaxBounds();
				BoundsMin = BoundsMin * _WorldToPartitionMul + _WorldToPartitionAdd;
				BoundsMax = BoundsMax * _WorldToPartitionMul + _WorldToPartitionAdd;

				BoundsMin.x = Math::Clamp(BoundsMin.x, 0.0f, PartitionGridSizeFloat - 1.0f);
				BoundsMin.y = Math::Clamp(BoundsMin.y, 0.0f, PartitionGridSizeFloat - 1.0f);
				BoundsMax.x = Math::Clamp(BoundsMax.x, 0.0f, PartitionGridSizeFloat - 1.0f);
				BoundsMax.y = Math::Clamp(BoundsMax.y, 0.0f, PartitionGridSizeFloat - 1.0f);

				uint32_t YMin = static_cast<uint32_t>(BoundsMin.y);
				uint32_t YMax = static_cast<uint32_t>(BoundsMax.y);
				uint32_t XMin = static_cast<uint32_t>(BoundsMin.x);
				uint32_t XMax = static_cast<uint32_t>(BoundsMax.x);

				OutPartitions.reserve((YMax - YMin + 1) * (XMax - XMin + 1));
				for (uint32_t Y = YMin; Y <= YMax; ++Y)
				{
					for (uint32_t X = XMin; X <= XMax; ++X)
						OutPartitions.push_back(&_Grid[PartitionMapping2DFunction(X, Y, PartitionGridSize)]);
				}
			}

			void GetPartitionsInRadius(_In_ const Vector2& InPosition, _In_ float InRadius, _Out_ vector<PartitionType*>& OutPartitions)
			{
				GetPartitionsInBounds(
					AxisAlignedRectangle(AxisAlignedRectangle::OriginAndExtent {
						InPosition, Vector2(InRadius)
					}),
					OutPartitions
				);
			}

			const Vector2& GetWorldMinBounds() const { return _WorldMinBounds; };
			const Vector2& GetWorldMaxBounds() const { return _WorldMaxBounds; }

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
			Vector2 _WorldToPartitionMul	= Vector2::Zero;
			Vector2 _WorldToPartitionAdd	= Vector2::Zero;
			Vector2 _WorldMinBounds			= Vector2::Zero;
			Vector2 _WorldMaxBounds			= Vector2::Zero;

		};
	}
}
