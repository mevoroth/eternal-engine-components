#include "GraphicData/GraphicObjects.hpp"

#include "Macros/Macros.hpp"

using namespace Eternal::GraphicData;

void GraphicObjects::SetGraphicGameObjects(_In_ vector<GraphicGameObject*>* GameObjects)
{
	ETERNAL_ASSERT(GameObjects);
	_GraphicGameObjects = GameObjects;
}

void GraphicObjects::SetMaterial(_In_ Material* MaterialObj)
{
	ETERNAL_ASSERT(MaterialObj);
	_Material = MaterialObj;
}

vector<GraphicGameObject*>& GraphicObjects::GetGraphicGameObjects()
{
	ETERNAL_ASSERT(_GraphicGameObjects);
	return *_GraphicGameObjects;
}

Material* GraphicObjects::GetMaterial()
{
	ETERNAL_ASSERT(_Material);
	return _Material;
}
