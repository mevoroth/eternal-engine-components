#include "Mesh/MeshFactory.hpp"

#include "Mesh/GenericMesh.hpp"
#include "Import/fbx/ImportFbx.hpp"
#include "d3d11/D3D11PosUVNormalVertexBuffer.hpp"
#include "d3d11/D3D11UInt32IndexBuffer.hpp"

namespace Eternal
{
	namespace Components
	{
		using namespace Eternal::Import;

		Mesh* CreateMesh(_In_ const char* MeshFile)
		{
			GenericMesh<D3D11PosUVNormalVertexBuffer::PosUVNormalVertex, D3D11PosUVNormalVertexBuffer, D3D11UInt32IndexBuffer>* NewMesh = new GenericMesh<D3D11PosUVNormalVertexBuffer::PosUVNormalVertex, D3D11PosUVNormalVertexBuffer, D3D11UInt32IndexBuffer>();
			ImportFbx::Get()->Import(MeshFile, *NewMesh);
			return NewMesh;
		}
	}
}
