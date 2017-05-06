#include "GraphicData/CommandQueues.hpp"

#include "GraphicsSettings.hpp"
#include "Graphics/CommandQueueFactory.hpp"

using namespace Eternal::GraphicData;

CommandQueues::CommandQueues()
	: StaticCollection<CommandQueueKey, CommandQueue, COMMAND_QUEUES_COUNT>()
{
}

void CommandQueues::Initialize(_In_ Device& DeviceObj)
{
	GetArray()[PRESENT_QUEUE] = CreateCommandQueue(DeviceObj, FRAME_LAG);

	for (uint32_t QueueIndex = GRAPHIC_QUEUE_0; QueueIndex < COMMAND_QUEUES_COUNT; ++QueueIndex)
	{
		GetArray()[QueueIndex] = CreateCommandQueue(DeviceObj, 16);
	}
}
