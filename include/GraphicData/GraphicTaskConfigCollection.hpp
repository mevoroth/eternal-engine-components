#ifndef _GRAPHIC_TASK_CONFIG_COLLECTION_HPP_
#define _GRAPHIC_TASK_CONFIG_COLLECTION_HPP_

#include "GraphicData/GraphicTaskConfig.hpp"

namespace Eternal
{
	namespace GraphicData
	{
		class GraphicTaskConfigCollection
		{
		public:
			enum GraphicTaskConfigKey
			{
				OPAQUE_TASK = 0,
				SHADOW_TASK,
				GRAPHICTASKCONFIG_COUNT
			};

			GraphicTaskConfigCollection();

			const GraphicTaskConfig& GetGraphicTaskConfig(_In_ const GraphicTaskConfigKey& Key);

		private:
			GraphicTaskConfig _GraphicTaskConfigs[GRAPHICTASKCONFIG_COUNT];
		};
	}
}

#endif
