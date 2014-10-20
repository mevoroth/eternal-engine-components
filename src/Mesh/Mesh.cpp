#include "Mesh/Mesh.hpp"

using namespace Eternal::Components;
using namespace Eternal::Graphics;

void Mesh::PushVertex(const Vertex& v)
{
	_vertices.push_back(v);
}

void Mesh::PushTriangle(uint16_t v1, uint16_t v2, uint16_t v3)
{
	_indices.push_back(v1);
	_indices.push_back(v2);
	_indices.push_back(v3);
}

void Mesh::PushMesh(const Mesh& mesh)
{
	_subMeshes.push_back(mesh);
}

const Vertex* Mesh::GetVertices() const
{
	return _vertices.data();
}
int Mesh::GetVerticesCount() const
{
	return _vertices.size();
}
const uint16_t* Mesh::GetIndices() const
{
	return _indices.data();
}
int Mesh::GetIndicesCount() const
{
	return _indices.size();
}

const Mesh* Mesh::GetSubMeshes() const
{
	return _subMeshes.data();
}
int Mesh::GetSubMeshesCount() const
{
	return _subMeshes.size();
}

Transform& Mesh::GetTransform()
{
	return _transform;
}

const Transform& Mesh::GetTransform() const
{
	return _transform;
}
