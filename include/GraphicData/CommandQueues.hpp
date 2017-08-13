#ifndef _COMMAND_QUEUES_HPP_
#define _COMMAND_QUEUES_HPP_

#include "GraphicData/StaticCollection.hpp"

namespace Eternal
{
	namespace Graphics
	{
		class Device;
		class CommandQueue;
		class Fence;
	}

	namespace GraphicData
	{
		using namespace Eternal::Graphics;

		enum CommandQueueKey
		{
			COMMAND_QUEUE_GRAPHIC	= 0,
			COMMAND_QUEUE_COMPUTE	= 1,
			COMMAND_QUEUE_COPY		= 2,
			//COMMAND_QUEUE_GRAPHIC_2		= 3,
			//COMMAND_QUEUE_GRAPHIC_3		= 4,
			//COMMAND_QUEUE_GRAPHIC_4		= 5,
			//COMMAND_QUEUE_GRAPHIC_5		= 6,
			//COMMAND_QUEUE_GRAPHIC_6		= 7,
			//COMMAND_QUEUE_GRAPHIC_7		= 8,
			//COMMAND_QUEUE_GRAPHIC_8		= 9,
			//COMMAND_QUEUE_GRAPHIC_9		= 10,
			//COMMAND_QUEUE_GRAPHIC_10	= 11,
			//COMMAND_QUEUE_GRAPHIC_11	= 12,
			//COMMAND_QUEUE_GRAPHIC_12	= 13,
			//COMMAND_QUEUE_GRAPHIC_13	= 14,
			//COMMAND_QUEUE_GRAPHIC_14	= 15,
			COMMAND_QUEUE_COUNT
		};

		struct GCommandQueue
		{
			CommandQueue*	Queue		= nullptr;
			Fence*			QueueFence	= nullptr;
		};

		class CommandQueues : public StaticCollection<CommandQueueKey, GCommandQueue, COMMAND_QUEUE_COUNT>
		{
		public:
			CommandQueues();
			virtual void Initialize(_In_ Device& DeviceObj) override;
		};
	}
}

#endif
