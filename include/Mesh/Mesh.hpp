#ifndef _MESH_HPP_
#define _MESH_HPP_

#include <cstdint>
#include <vector>

#include "Transform/Transform.hpp"
#include "Graphics/Vertex.hpp"

namespace Eternal
{
	namespace Components
	{
		class Mesh
		{
		private:
			Transform _transform;
			std::vector<Graphics::Vertex> _vertices;
			std::vector<uint16_t> _indices;
			std::vector<Mesh> _subMeshes;
		public:
			void PushVertex(const Graphics::Vertex& v);
			void PushTriangle(uint16_t v1, uint16_t v2, uint16_t v3);
			void PushMesh(const Mesh& mesh);

			const Graphics::Vertex* GetVertices() const;
			int GetVerticesCount() const;
			const uint16_t* GetIndices() const;
			int GetIndicesCount() const;

			Transform& GetTransform();
		};
	}
}

#endif
