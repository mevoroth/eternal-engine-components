#ifndef _MESH_FACTORY_HPP_
#define _MESH_FACTORY_HPP_

namespace Eternal
{
	namespace Components
	{
		class Mesh;

		void CreateMesh(_In_ const char* MeshFile, _Out_ Mesh*& OutMesh, _Out_ Mesh*& OutBoundingBox);
	}
}

#endif
