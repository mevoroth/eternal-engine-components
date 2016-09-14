#ifndef _RENDERING_LIST_COLLECTION_HPP_
#define _RENDERING_LIST_COLLECTION_HPP_

#include <vector>

namespace Eternal
{
	namespace Core
	{
		class GameObject;
	}

	namespace GraphicData
	{
		using namespace std;
		using namespace Eternal::Core;

		class RenderingListCollection
		{
		public:
			enum RenderingListKey
			{
				OPAQUE_LIST = 0,
				RENDERINGLISTS_COUNT
			};

			void Add(_In_ const RenderingListKey& Key, _In_ GameObject* Object);
			void Remove(_In_ const RenderingListKey& Key, _In_ GameObject* Object);
			GameObject* Get(_In_ const RenderingListKey& Key, _In_ int ObjectIndex);
			size_t GetSize(_In_ const RenderingListKey& Key) const;

		private:
			vector<GameObject*> _RenderingLists[RENDERINGLISTS_COUNT];
		};
	}
}

#endif
