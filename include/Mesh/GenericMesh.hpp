#ifndef _GENERIC_MESH_HPP_
#define _GENERIC_MESH_HPP_

#include <cstdint>
#include <vector>

#include "Macros/Macros.hpp"
#include "Mesh/Mesh.hpp"
#include "Transform/Transform.hpp"

using namespace std;

namespace Eternal
{
	namespace Components
	{
		template<class VertexT, class VertexBufferT, class IndexBufferT>
		class GenericMesh : public Mesh
		{
		public:
			void PushVertex(const VertexT& V);
			void PushTriangle(uint32_t V1, uint32_t V2, uint32_t V3);
			void PushMesh(const GenericMesh<VertexT, VertexBufferT, IndexBufferT>& SubMesh);

			virtual VertexBuffer* GetVertexBuffer() override;
			virtual IndexBuffer* GetIndexBuffer() override;

			virtual Transform& GetTransform() override;
			virtual const Transform& GetTransform() const override;

			virtual Mesh& GetSubMesh(uint32_t Index) override;
			virtual size_t GetSubMeshesCount() override;

			virtual bool IsValidNode() const override;
			virtual bool IsValid() const override;

		private:
			Transform _Transform;

			vector<GenericMesh> _SubMeshes;
			vector<VertexT> _Vertices;
			vector<uint32_t> _Indices;
		};

		template<class VertexT, class VertexBufferT, class IndexBufferT>
		void GenericMesh<VertexT, VertexBufferT, IndexBufferT>::PushVertex(const VertexT& V)
		{
			_Vertices.push_back(V);
		}

		template<class VertexT, class VertexBufferT, class IndexBufferT>
		void GenericMesh<VertexT, VertexBufferT, IndexBufferT>::PushTriangle(uint32_t V1, uint32_t V2, uint32_t V3)
		{
			_Indices.push_back(V1);
			_Indices.push_back(V2);
			_Indices.push_back(V3);
		}

		template<class VertexT, class VertexBufferT, class IndexBufferT>
		void GenericMesh<VertexT, VertexBufferT, IndexBufferT>::PushMesh(const GenericMesh<VertexT, VertexBufferT, IndexBufferT>& SubMesh)
		{
			_SubMeshes.push_back(SubMesh);
		}

		template<class VertexT, class VertexBufferT, class IndexBufferT>
		Transform& GenericMesh<VertexT, VertexBufferT, IndexBufferT>::GetTransform()
		{
			return _Transform;
		}

		template<class VertexT, class VertexBufferT, class IndexBufferT>
		const Transform& GenericMesh<VertexT, VertexBufferT, IndexBufferT>::GetTransform() const
		{
			return _Transform;
		}

		template<class VertexT, class VertexBufferT, class IndexBufferT>
		VertexBuffer* GenericMesh<VertexT, VertexBufferT, IndexBufferT>::GetVertexBuffer()
		{
			if (!_VerticesBuffer)
			{
				_VerticesBuffer = new VertexBufferT(_Vertices);
			}
			return _VerticesBuffer;
		}

		template<class VertexT, class VertexBufferT, class IndexBufferT>
		IndexBuffer* GenericMesh<VertexT, VertexBufferT, IndexBufferT>::GetIndexBuffer()
		{
			if (!_IndicesBuffer)
			{
				_IndicesBuffer = new IndexBufferT(_Indices);
			}
			return _IndicesBuffer;
		}

		template<class VertexT, class VertexBufferT, class IndexBufferT>
		Mesh& GenericMesh<VertexT, VertexBufferT, IndexBufferT>::GetSubMesh(uint32_t Index)
		{
			ETERNAL_ASSERT(Index < _SubMeshes.size());
			return _SubMeshes[Index];
		}

		template<class VertexT, class VertexBufferT, class IndexBufferT>
		size_t GenericMesh<VertexT, VertexBufferT, IndexBufferT>::GetSubMeshesCount()
		{
			return _SubMeshes.size();
		}

		template<class VertexT, class VertexBufferT, class IndexBufferT>
		bool GenericMesh<VertexT, VertexBufferT, IndexBufferT>::IsValidNode() const
		{
			return _Vertices.size() > 0;
		}

		template<class VertexT, class VertexBufferT, class IndexBufferT>
		bool GenericMesh<VertexT, VertexBufferT, IndexBufferT>::IsValid() const
		{
			if (_Vertices.size() > 0)
			{
				return true;
			}
			for (uint32_t SubMeshIndex = 0; SubMeshIndex < _SubMeshes.size(); ++SubMeshIndex)
			{
				if (_SubMeshes[SubMeshIndex].IsValid())
				{
					return true;
				}
			}
			return false;
		}

	}
}

#endif
