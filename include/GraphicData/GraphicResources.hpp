#ifndef _GRAPHIC_RESOURCES_HPP_
#define _GRAPHIC_RESOURCES_HPP_

#include "GraphicData/StaticCollection.hpp"

namespace Eternal
{
	namespace Graphics
	{
		class Device;
	}

	namespace GraphicData
	{
		using namespace Eternal::Graphics;

		class CommandQueues;
		class StaticSamplers;
		class Viewports;

		class GraphicResources : public StaticCollectionInitialization
		{
		public:
			GraphicResources();
			~GraphicResources();

			CommandQueues* GetCommandQueues()
			{
				return _Collections.CommandQueuesResources;
			}

			StaticSamplers* GetStaticSamplers()
			{
				return _Collections.StaticSamplersResources;
			}

			Viewports* GetViewports()
			{
				return _Collections.ViewportsResources;
			}

			virtual void Initialize(_In_ Device& DeviceObj) override;

		private:
			union Collections
			{
				struct
				{
					CommandQueues*	CommandQueuesResources;
					StaticSamplers*	StaticSamplersResources;
					Viewports*		ViewportsResources;
				};
				StaticCollectionInitialization* Initializers[3];
			};

			Collections _Collections;
		};
	}
}

#endif
