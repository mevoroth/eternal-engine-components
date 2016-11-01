#ifndef _GRAPHIC_TASK_CONFIG_HPP_
#define _GRAPHIC_TASK_CONFIG_HPP_

#include <vector>
#include <string>
#include "GraphicData/BlendStateCollection.hpp"
#include "GraphicData/ViewportCollection.hpp"

namespace Eternal
{
	namespace GraphicData
	{
		using namespace std;

		struct GraphicTaskConfig 
		{
			const char* PS = nullptr;
			const char* PSFile = nullptr;
			vector<string> Defines;
			BlendStateCollection::BlendStateKey BlendConfig;
			ViewportCollection::ViewportKey ViewportConfig;
		};
	}
}

#endif
