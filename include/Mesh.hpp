#ifndef _MESH_HPP_
#define _MESH_HPP_

#include <cstdint>

#include "Graphics/Vertex.hpp"

namespace Eternal
{
	namespace Components
	{
		class Mesh
		{
		private:
			Transform _transform;
			Graphics::Vertex* _vertices;
			uint16_t* _indices;
		public:
			void PushVertex(Graphics::Vertex* v);
			void PushTriangle(uint16_t v1, uint16_t v2, uint16_t v3);

			Graphics::Vertex* GetVertices() const;
			int GetVerticesCount() const;
			uint16_t* GetIndices() const;
			int GetIndicesCount() const;
		};
	}
}

#endif
