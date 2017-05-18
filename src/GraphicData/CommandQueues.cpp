#include "GraphicData/CommandQueues.hpp"

#include "GraphicsSettings.hpp"
#include "Graphics/CommandQueueFactory.hpp"

using namespace Eternal::GraphicData;

CommandQueues::CommandQueues()
	: StaticCollection<CommandQueueKey, CommandQueue, COMMAND_QUEUE_COUNT>()
{
}

void CommandQueues::Initialize(_In_ Device& DeviceObj)
{
	GetArray()[COMMAND_QUEUE_PRESENT] = CreateCommandQueue(DeviceObj, FRAME_LAG);

	for (uint32_t QueueIndex = COMMAND_QUEUE_GRAPHIC_0; QueueIndex < COMMAND_QUEUE_COUNT; ++QueueIndex)
	{
		GetArray()[QueueIndex] = CreateCommandQueue(DeviceObj, 16);
	}
}
