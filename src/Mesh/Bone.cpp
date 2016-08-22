#include "Mesh/Bone.hpp"

using namespace Eternal::Components;

void Bone::PushInfluence(_In_ uint32_t Index, _In_ float Weight)
{
	IndexWeight Influence = {
		Index, Weight
	};
	_Influence.push_back(Influence);
}
