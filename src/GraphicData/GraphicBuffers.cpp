#include "GraphicData/GraphicBuffers.hpp"

#include <cwchar>
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

	RootSignatureParameter GraphicsBuffersParameters[] =
	{
		{ RootSignatureParameterType::ROOT_SIGNATURE_PARAMETER_RENDER_TARGET, RootSignatureAccess::ROOT_SIGNATURE_ACCESS_IA_VS_PS, 0 },
		{ RootSignatureParameterType::ROOT_SIGNATURE_PARAMETER_RENDER_TARGET, RootSignatureAccess::ROOT_SIGNATURE_ACCESS_IA_VS_PS, 1 },
		{ RootSignatureParameterType::ROOT_SIGNATURE_PARAMETER_RENDER_TARGET, RootSignatureAccess::ROOT_SIGNATURE_ACCESS_IA_VS_PS, 2 },
		{ RootSignatureParameterType::ROOT_SIGNATURE_PARAMETER_RENDER_TARGET, RootSignatureAccess::ROOT_SIGNATURE_ACCESS_IA_VS_PS, 3 }
	};

	RootSignatureParameter DepthBufferParameter = { RootSignatureParameterType::ROOT_SIGNATURE_PARAMETER_DEPTH_STENCIL, RootSignatureAccess::ROOT_SIGNATURE_ACCESS_IA_VS_PS, 0 };

	_GraphicBuffersDescriptorHeap	= CreateDescriptorHeap(DeviceObj, GraphicsBuffersParameters,	ETERNAL_ARRAYSIZE(GraphicsBuffersParameters));
	_DepthStencilDescriptorHeap		= CreateDescriptorHeap(DeviceObj, &DepthBufferParameter,		1);

	wchar_t GraphicBufferName[256];
	for (uint32_t GraphicBufferIndex = 0; GraphicBufferIndex < GRAPHIC_BUFFER_NO_DEPTH_COUNT; ++GraphicBufferIndex)
	{
		swprintf(GraphicBufferName, ETERNAL_ARRAYSIZE(GraphicBufferName), L"Graphic Buffer %d", GraphicBufferIndex);
		_GraphicBuffersHeap[GraphicBufferIndex]		= CreateHeap(DeviceObj, HEAP_TYPE_RENDER_TARGET_DEPTH_STENCIL, 1, true, false, false, false);
		_GraphicBuffersResource[GraphicBufferIndex]	= CreateResource(DeviceObj, *_GraphicBuffersHeap[GraphicBufferIndex], GraphicBufferName, RESOURCE_DIMENSION_TEXTURE_2D, GraphicBufferFormats[GraphicBufferIndex], TEXTURE_RENDER_TARGET, Width, Height, 1, 1, TRANSITION_UNDEFINED);
		GetArray()[GraphicBufferIndex]				= _GraphicBuffersResource[GraphicBufferIndex]->CreateRenderTargetView(DeviceObj, *_GraphicBuffersDescriptorHeap, GraphicBufferFormats[GraphicBufferIndex]);
	}

	_GraphicBuffersHeap[GRAPHIC_BUFFER_DEPTH]		= CreateHeap(DeviceObj, HEAP_TYPE_RENDER_TARGET_DEPTH_STENCIL, 1, true, false, false, false);
	_GraphicBuffersResource[GRAPHIC_BUFFER_DEPTH]	= CreateResource(DeviceObj, *_GraphicBuffersHeap[GRAPHIC_BUFFER_DEPTH], L"Depth Buffer", RESOURCE_DIMENSION_TEXTURE_2D, GraphicBufferFormats[GRAPHIC_BUFFER_DEPTH], TEXTURE_DEPTH_STENCIL, Width, Height, 1, 1, TRANSITION_UNDEFINED);
	GetArray()[GRAPHIC_BUFFER_DEPTH]				= _GraphicBuffersResource[GRAPHIC_BUFFER_DEPTH]->CreateDepthStencilView(DeviceObj, *_DepthStencilDescriptorHeap, GraphicBufferFormats[GRAPHIC_BUFFER_DEPTH]);
}

Resource* GraphicBuffers::GetResource(_In_ const GraphicBufferKey& Key)
{
	return _GraphicBuffersResource[Key];
}
