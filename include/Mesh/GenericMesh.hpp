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
			void PushVertex(_In_ const VertexT& V);
			void PushTriangle(_In_ uint32_t V1, _In_ uint32_t V2, _In_ uint32_t V3);
			void PushMesh(_In_ const GenericMesh<VertexT, VertexBufferT, IndexBufferT>& SubMesh);
			inline VertexT& GetVertex(_In_ uint32_t VertexIndex)
			{
				ETERNAL_ASSERT(VertexIndex < GetVerticesCount());
				return _Vertices[VertexIndex];
			}
			inline uint32_t GetVerticesCount()
			{
				return _Vertices.size();
			}

			virtual void InitializeBuffers() override;
			virtual void DestroyBuffers() override;
			virtual VertexBuffer* GetVertexBuffer() override;
			virtual IndexBuffer* GetIndexBuffer() override;

			virtual Transform& GetTransform() override;
			virtual const Transform& GetTransform() const override;

			virtual Mesh& GetSubMesh(_In_ uint32_t Index) override;
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
		void GenericMesh<VertexT, VertexBufferT, IndexBufferT>::PushVertex(_In_ const VertexT& V)
		{
			_Vertices.push_back(V);
		}

		template<class VertexT, class VertexBufferT, class IndexBufferT>
		void GenericMesh<VertexT, VertexBufferT, IndexBufferT>::PushTriangle(_In_ uint32_t V1, _In_ uint32_t V2, _In_ uint32_t V3)
		{
			_Indices.push_back(V1);
			_Indices.push_back(V2);
			_Indices.push_back(V3);
		}

		template<class VertexT, class VertexBufferT, class IndexBufferT>
		void GenericMesh<VertexT, VertexBufferT, IndexBufferT>::PushMesh(_In_ const GenericMesh<VertexT, VertexBufferT, IndexBufferT>& SubMesh)
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
		void GenericMesh<VertexT, VertexBufferT, IndexBufferT>::InitializeBuffers()
		{
			ETERNAL_ASSERT(_Vertices.size());
			ETERNAL_ASSERT(_Indices.size());
			ETERNAL_ASSERT(!(_Indices.size() % 3));
			ETERNAL_ASSERT(!_VerticesBuffer);
			ETERNAL_ASSERT(!_IndicesBuffer);
			_VerticesBuffer = new VertexBufferT(_Vertices);
			_IndicesBuffer = new IndexBufferT(_Indices);
		}

		template<class VertexT, class VertexBufferT, class IndexBufferT>
		void GenericMesh<VertexT, VertexBufferT, IndexBufferT>::DestroyBuffers()
		{
			ETERNAL_ASSERT(_VerticesBuffer);
			ETERNAL_ASSERT(_IndicesBuffer);
			delete _VerticesBuffer;
			_VerticesBuffer = nullptr;
			delete _IndicesBuffer;
			_IndicesBuffer = nullptr;
		}

		template<class VertexT, class VertexBufferT, class IndexBufferT>
		VertexBuffer* GenericMesh<VertexT, VertexBufferT, IndexBufferT>::GetVertexBuffer()
		{
			ETERNAL_ASSERT(_VerticesBuffer);
			return _VerticesBuffer;
		}

		template<class VertexT, class VertexBufferT, class IndexBufferT>
		IndexBuffer* GenericMesh<VertexT, VertexBufferT, IndexBufferT>::GetIndexBuffer()
		{
			ETERNAL_ASSERT(_IndicesBuffer);
			return _IndicesBuffer;
		}

		template<class VertexT, class VertexBufferT, class IndexBufferT>
		Mesh& GenericMesh<VertexT, VertexBufferT, IndexBufferT>::GetSubMesh(_In_ uint32_t Index)
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
