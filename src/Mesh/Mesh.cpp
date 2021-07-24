#include "Mesh/Mesh.hpp"

namespace Eternal
{
	namespace Components
	{
		void Mesh::SetPerDrawConstantBufferViewVS(_In_ uint32_t InSubMeshIndex, _In_ View* InConstantBuffer)
		{
			ETERNAL_ASSERT(InSubMeshIndex < _GPUMesh.PerDrawInformations.size());
			_GPUMesh.PerDrawInformations[InSubMeshIndex].PerDrawConstantBufferVS = InConstantBuffer;
		}

		MeshCollection::~MeshCollection()
		{
			for (uint32_t MeshIndex = 0; MeshIndex < Meshes.size(); ++MeshIndex)
			{
				delete Meshes[MeshIndex];
				Meshes[MeshIndex] = nullptr;
			}
		}
	}
}
