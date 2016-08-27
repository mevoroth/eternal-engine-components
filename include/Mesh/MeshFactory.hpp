#ifndef _MESH_FACTORY_HPP_
#define _MESH_FACTORY_HPP_

namespace Eternal
{
	namespace Components
	{
		class Mesh;

		Mesh* CreateMesh(_In_ const char* MeshFile);
	}
}

#endif
