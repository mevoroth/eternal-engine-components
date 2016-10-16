#include "Mesh/MeshFactory.hpp"

#include "Mesh/GenericMesh.hpp"
#include "GraphicData/VertexFormat.hpp"
#include "Import/fbx/ImportFbx.hpp"

namespace Eternal
{
	namespace Components
	{
		using namespace Eternal::Import;
		using namespace Eternal::GraphicData;

		Mesh* CreateMesh(_In_ const char* MeshFile)
		{
			Mesh* NewMesh = nullptr;
			ImportFbx::Get()->Import(MeshFile, NewMesh);
			return NewMesh;
		}
	}
}
