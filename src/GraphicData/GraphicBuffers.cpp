#include "GraphicData/GraphicBuffers.hpp"

#include <cstdint>
#include "Graphics/HeapFactory.hpp"
#include "Graphics/ResourceFactory.hpp"
#include "Graphics/CommandList.hpp"
#include "Graphics/DescriptorHeapFactory.hpp"
#include "Graphics/RootSignature.hpp"
#include "Graphics/Heap.hpp"
#include "NextGenGraphics/Resource.hpp"
#include "Vulkan/VulkanFormat.hpp"

using namespace Eternal::GraphicData;
using namespace Eternal::Graphics;

GraphicBuffers::GraphicBuffers()
	: StaticCollection<GraphicBufferKey, View, GRAPHIC_BUFFER_COUNT>()
{
}

void GraphicBuffers::Initialize(_In_ Device& DeviceObj)
{
	const Format GraphicBufferFormats[] =
	{
		FORMAT_RGBA8888,
		FORMAT_RGBA8888,
		FORMAT_RGBA8888,
		FORMAT_RGBA8888,
		FORMAT_D32
	};

	ETERNAL_STATIC_ASSERT(ETERNAL_ARRAYSIZE(GraphicBufferFormats) == GRAPHIC_BUFFER_COUNT, "Graphic Buffers formats not implemented");

	const uint32_t Width = 1280;
	const uint32_t Height = 720;
	const uint32_t Size = Width * Height;

	_GraphicBuffersDescriptorHeap = CreateDescriptorHeap(DeviceObj, 0, ROOT_SIGNATURE_PARAMETER_RENDER_TARGET, GRAPHIC_BUFFER_COUNT, (RootSignatureAccess)(ROOT_SIGNATURE_IA | ROOT_SIGNATURE_VS | ROOT_SIGNATURE_PS));
	
	for (uint32_t GraphicBufferIndex = 0; GraphicBufferIndex < GRAPHIC_BUFFER_NO_DEPTH_COUNT; ++GraphicBufferIndex)
	{
		_GraphicBuffersHeap[GraphicBufferIndex]		= CreateHeap(DeviceObj, 1, true, false, false, false);
		_GraphicBuffersResource[GraphicBufferIndex]	= CreateResource(DeviceObj, *_GraphicBuffersHeap[GraphicBufferIndex], RESOURCE_DIMENSION_TEXTURE_2D, GraphicBufferFormats[GraphicBufferIndex], TEXTURE_RENDER_TARGET, Width, Height, 1, 1, TRANSITION_UNDEFINED);
		GetArray()[GraphicBufferIndex]				= _GraphicBuffersResource[GraphicBufferIndex]->CreateRenderTargetView(DeviceObj, *_GraphicBuffersDescriptorHeap, GraphicBufferFormats[GraphicBufferIndex]);
	}

	_GraphicBuffersHeap[GRAPHIC_BUFFER_DEPTH]		= CreateHeap(DeviceObj, 1, true, false, false, false);
	_GraphicBuffersResource[GRAPHIC_BUFFER_DEPTH]	= CreateResource(DeviceObj, *_GraphicBuffersHeap[GRAPHIC_BUFFER_DEPTH], RESOURCE_DIMENSION_TEXTURE_2D, GraphicBufferFormats[GRAPHIC_BUFFER_DEPTH], TEXTURE_DEPTH_STENCIL, Width, Height, 1, 1, TRANSITION_UNDEFINED);
	GetArray()[GRAPHIC_BUFFER_DEPTH]				= _GraphicBuffersResource[GRAPHIC_BUFFER_DEPTH]->CreateDepthStencilView(DeviceObj, *_GraphicBuffersDescriptorHeap, GraphicBufferFormats[GRAPHIC_BUFFER_DEPTH]);
}
