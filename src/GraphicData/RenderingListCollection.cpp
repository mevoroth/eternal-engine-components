#include "GraphicData/RenderingListCollection.hpp"

#include <algorithm>
#include "Core/GameObject.hpp"

using namespace Eternal::GraphicData;

void RenderingListCollection::Add(_In_ const RenderingListKey& Key, _In_ GameObject* Object)
{
	_RenderingLists[Key].push_back(Object);
}

void RenderingListCollection::Remove(_In_ const RenderingListKey& Key, _In_ GameObject* Object)
{
	vector<GameObject*>& RenderingList = _RenderingLists[Key];
	_RenderingLists[Key].erase(find(RenderingList.cbegin(), RenderingList.cend(), Object));
}

GameObject* RenderingListCollection::Get(_In_ const RenderingListKey& Key, _In_ int ObjectIndex)
{
	return _RenderingLists[Key][ObjectIndex];
}

size_t RenderingListCollection::GetSize(_In_ const RenderingListKey& Key) const
{
	return _RenderingLists[Key].size();
}
