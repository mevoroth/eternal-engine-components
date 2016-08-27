#ifndef _GRAPHIC_OBJECTS_HPP_
#define _GRAPHIC_OBJECTS_HPP_

#include <vector>

namespace Eternal
{
	namespace Core
	{
		class GraphicGameObject;
	}

	namespace GraphicData
	{
		using namespace std;
		using namespace Eternal::Core;

		class Material;

		class GraphicObjects
		{
		public:
			void SetGraphicGameObjects(_In_ vector<GraphicGameObject*>* GameObjects);
			void SetMaterial(_In_ Material* MaterialObj);

			vector<GraphicGameObject*>& GetGraphicGameObjects();
			Material* GetMaterial();

		private:
			vector<GraphicGameObject*>* _GraphicGameObjects;
			Material* _Material = nullptr;
		};
	}
}

#endif
