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
		class GraphicBuffers;
		class Shaders;
		class BlendStates;

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

			GraphicBuffers* GetGraphicBuffers()
			{
				return _Collections.GraphicBuffersResources;
			}

			Shaders* GetShaders()
			{
				return _Collections.ShadersResources;
			}

			BlendStates* GetBlendStates()
			{
				return _Collections.BlendStatesResources;
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
					GraphicBuffers*	GraphicBuffersResources;
					Shaders*		ShadersResources;
					BlendStates*	BlendStatesResources;
				};
				StaticCollectionInitialization* Initializers[6];
			};

			Collections _Collections;
		};
	}
}

#endif
