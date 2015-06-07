#ifndef _MESH_HPP_
#define _MESH_HPP_

#include <cstdint>
#include <vector>

#include "Transform/Transform.hpp"

using namespace std;

namespace Eternal
{
	namespace Components
	{
		template<class VertexT, class VertexBufferT, class IndexBufferT>
		class Mesh
		{
		public:
			Mesh();

			void PushVertex(const VertexT& V);
			void PushTriangle(uint32_t V1, uint32_t V2, uint32_t V3);
			void PushMesh(const Mesh<VertexT, VertexBufferT, IndexBufferT>& SubMesh);

			Transform& GetTransform();
			const Transform& GetTransform() const;

		private:
			Transform _Transform;

			VertexBufferT _VertexBuffer;
			IndexBufferT _IndexBuffer;
			vector<Mesh> _SubMeshes;
			vector<VertexT> _Vertices;
			vector<uint32_t> _Indices;
		};

		template<class VertexT, class VertexBufferT, class IndexBufferT>
		Mesh<VertexT, VertexBufferT, IndexBufferT>::Mesh()
			: _VertexBuffer(_Vertices)
			, _IndexBuffer(_Indices)
		{
		}

		template<class VertexT, class VertexBufferT, class IndexBufferT>
		void Mesh<VertexT, VertexBufferT, IndexBufferT>::PushVertex(const VertexT& V)
		{
			_Vertices.push_back(V);
		}

		template<class VertexT, class VertexBufferT, class IndexBufferT>
		void Mesh<VertexT, VertexBufferT, IndexBufferT>::PushTriangle(uint32_t V1, uint32_t V2, uint32_t V3)
		{
			_Indices.push_back(V1);
			_Indices.push_back(V2);
			_Indices.push_back(V3);
		}

		template<class VertexT, class VertexBufferT, class IndexBufferT>
		void Mesh<VertexT, VertexBufferT, IndexBufferT>::PushMesh(const Mesh<VertexT, VertexBufferT, IndexBufferT>& SubMesh)
		{
			_SubMeshes.push_back(SubMesh);
		}

		template<class VertexT, class VertexBufferT, class IndexBufferT>
		Transform& Mesh<VertexT, VertexBufferT, IndexBufferT>::GetTransform()
		{
			return _Transform;
		}

		template<class VertexT, class VertexBufferT, class IndexBufferT>
		const Transform& Mesh<VertexT, VertexBufferT, IndexBufferT>::GetTransform() const
		{
			return _Transform;
		}
	}
}

#endif
