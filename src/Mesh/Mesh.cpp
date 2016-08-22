#include "Mesh/Mesh.hpp"

using namespace Eternal::Components;

void Mesh::SetBone(_In_ Bone* BoneObj)
{
	_Bone = BoneObj;
}

Bone* Mesh::GetBone()
{
	return _Bone;
}
