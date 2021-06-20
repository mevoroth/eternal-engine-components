#include "GraphicData/CommandQueues.hpp"

#include "GraphicsSettings.hpp"
#include "Graphics_deprecated/CommandQueueFactory.hpp"
#include "Graphics_deprecated/FenceFactory.hpp"

using namespace Eternal::GraphicData;

CommandQueues::CommandQueues()
	: StaticCollection<CommandQueueKey, GCommandQueue, COMMAND_QUEUE_COUNT>()
{
}

void CommandQueues::Initialize(_In_ Device& DeviceObj)
{
	GetArray()[COMMAND_QUEUE_GRAPHIC]			= new GCommandQueue;
	GetArray()[COMMAND_QUEUE_GRAPHIC]->Queue	= CreateCommandQueue(DeviceObj, COMMAND_LIST_TYPE_GRAPHIC);

	//for (uint32_t QueueIndex = COMMAND_QUEUE_GRAPHIC_0; QueueIndex < COMMAND_QUEUE_COUNT; ++QueueIndex)
	//{
	//	GetArray()[QueueIndex]				= new GCommandQueue;
	//	GetArray()[QueueIndex]->Queue		= CreateCommandQueue(DeviceObj, 16);
	//	GetArray()[QueueIndex]->QueueFence	= CreateFence(DeviceObj, FRAME_LAG);
	//}
}
