#ifndef _COMMAND_QUEUES_HPP_
#define _COMMAND_QUEUES_HPP_

#include "GraphicData/StaticCollection.hpp"

namespace Eternal
{
	namespace Graphics
	{
		class Device;
		class CommandQueue;
	}

	namespace GraphicData
	{
		enum CommandQueueKey
		{
			PRESENT_QUEUE		= 0,
			GRAPHIC_QUEUE_0		= 1,
			GRAPHIC_QUEUE_1		= 2,
			GRAPHIC_QUEUE_2		= 3,
			GRAPHIC_QUEUE_3		= 4,
			GRAPHIC_QUEUE_4		= 5,
			GRAPHIC_QUEUE_5		= 6,
			GRAPHIC_QUEUE_6		= 7,
			GRAPHIC_QUEUE_7		= 8,
			GRAPHIC_QUEUE_8		= 9,
			GRAPHIC_QUEUE_9		= 10,
			GRAPHIC_QUEUE_10	= 11,
			GRAPHIC_QUEUE_11	= 12,
			GRAPHIC_QUEUE_12	= 13,
			GRAPHIC_QUEUE_13	= 14,
			GRAPHIC_QUEUE_14	= 15,
			COMMAND_QUEUES_COUNT
		};
		class CommandQueues : public StaticCollection<CommandQueueKey, CommandQueue, COMMAND_QUEUES_COUNT>
		{
		public:
			CommandQueues();
			virtual void Initialize(_In_ Device& DeviceObj) override;
		};
	}
}

#endif
