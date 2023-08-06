#include "Mesh/Mesh.hpp"
#include "Graphics/GraphicsInclude.hpp"

namespace Eternal
{
	namespace Components
	{
		void Mesh::SetPerDrawConstantBufferViewMSVS(_In_ uint32_t InSubMeshIndex, _In_ View* InConstantBuffer)
		{
			ETERNAL_ASSERT(InSubMeshIndex < _GPUMesh.PerDrawInformations.size());
			_GPUMesh.PerDrawInformations[InSubMeshIndex].PerDrawConstantBufferMSVS = InConstantBuffer;
		}

		MeshCollection::~MeshCollection()
		{
			for (uint32_t MeshIndex = 0; MeshIndex < Meshes.size(); ++MeshIndex)
			{
				delete Meshes[MeshIndex];
				Meshes[MeshIndex] = nullptr;
			}
			DestroyAccelerationStructure(MeshCollectionAccelerationStructure);
			ETERNAL_BREAK(); // Mesh cleaning not implemented yet
		}
	}
}
