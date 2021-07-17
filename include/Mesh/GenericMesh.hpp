#pragma once

#include "Mesh/Mesh.hpp"

namespace Eternal
{
	namespace Components
	{
		using namespace std;

		template<class VertexT, typename IndexT = uint16_t>
		class GenericMesh final : public Mesh
		{
		public:
			void PushVertex(_In_ const VertexT& V)
			{
				_Vertices.push_back(V);
			}

			void PushTriangle(_In_ IndexT V0, _In_ IndexT V1, _In_ IndexT V2)
			{
				_Indices.push_back(V0);
				_Indices.push_back(V1);
				_Indices.push_back(V2);
			}

			inline VertexT& GetVertex(_In_ uint32_t VertexIndex)
			{
				ETERNAL_ASSERT(VertexIndex < GetVerticesCount());
				return _Vertices[VertexIndex];
			}
			inline uint32_t GetVerticesCount()
			{
				return static_cast<uint32_t>(_Vertices.size());
			}

			virtual uint32_t GetVerticesCount() const override
			{
				return static_cast<uint32_t>(_Vertices.size());
			}

			virtual uint32_t GetIndicesCount() const override
			{
				return static_cast<uint32_t>(_Indices.size());
			}

			virtual bool IsValidNode() const override
			{
				return _Vertices.size() > 0;
			}
			virtual bool IsValid() const override
			{
				if (_Vertices.size() > 0)
				{
					return true;
				}
				for (uint32_t SubMeshIndex = 0; SubMeshIndex < _SubMeshes.size(); ++SubMeshIndex)
				{
					if (_SubMeshes[SubMeshIndex]->IsValid())
					{
						return true;
					}
				}
				return false;
			}

		private:
			vector<IndexT>	_Indices;
			vector<VertexT>	_Vertices;
		};
	}
}
