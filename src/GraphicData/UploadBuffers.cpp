#include "GraphicData/UploadBuffers.hpp"

#include "GraphicsSettings.hpp"
#include <cwchar>
#include "Graphics_deprecated/Heap.hpp"
#include "Graphics_deprecated/HeapFactory.hpp"
#include "Graphics_deprecated/ResourceFactory.hpp"
#include "Graphics_deprecated/Format.hpp"
#include "Graphics/CommandList.hpp"
#include "NextGenGraphics/Resource.hpp"

using namespace Eternal::GraphicData;

UploadBuffers::UploadBuffers()
	: StaticCollection<UploadBufferKey, FreeList<Resource*>, UPLOAD_BUFFER_COUNT>()
{
}

UploadBuffers::~UploadBuffers()
{
	for (uint32_t UploadBufferIndex = 0; UploadBufferIndex < _UploadBuffers.size(); ++UploadBufferIndex)
	{
		delete _UploadBuffers[UploadBufferIndex];
	}
}

void UploadBuffers::Initialize(_In_ Device& DeviceObj)
{
	//_UploadBuffers.resize(UPLOAD_BUFFER_COUNT * UPLOAD_BUFFER_PER_HEAP);

	//wchar_t UploadBufferName[256];
	////for (uint32_t UploadBufferType = 0; UploadBufferType < UPLOAD_BUFFER_COUNT; ++UploadBufferType)
	////{
	////	_UploadHeaps[UploadBufferType]	= CreateHeap(DeviceObj, HEAP_TYPE_BUFFER, UPLOAD_BUFFER_PER_HEAP, false, true, true, false);
	////	GetArray()[UploadBufferType]	= new FreeList<Resource*>(UPLOAD_BUFFER_PER_HEAP);
	////}
	//_UploadHeaps[UPLOAD_BUFFER_BUFFER]	= CreateHeap(DeviceObj, HEAP_TYPE_BUFFER, UPLOAD_BUFFER_PER_HEAP, false, true, true, false);
	//GetArray()[UPLOAD_BUFFER_BUFFER]	= new FreeList<Resource*>(UPLOAD_BUFFER_PER_HEAP);

	//_UploadHeaps[UPLOAD_BUFFER_TEXTURE]	= CreateHeap(DeviceObj, HEAP_TYPE_TEXTURE, UPLOAD_BUFFER_PER_HEAP, false, true, true, false);
	//GetArray()[UPLOAD_BUFFER_TEXTURE]	= new FreeList<Resource*>(UPLOAD_BUFFER_PER_HEAP);

	//for (uint32_t UploadBufferIndex = 0; UploadBufferIndex < UPLOAD_BUFFER_PER_HEAP; ++UploadBufferIndex)
	//{
	//	swprintf(UploadBufferName, ETERNAL_ARRAYSIZE(UploadBufferName), L"Upload Buffer %d", UploadBufferIndex);
	//	Resource* UploadBuffer		= CreateResource(DeviceObj, *_UploadHeaps[UPLOAD_BUFFER_BUFFER], UploadBufferName, sizeof(float) * 4, UPLOAD_BUFFER_SIZE * sizeof(float) * 4, BUFFER_COPY_READ);
	//	GetArray()[UPLOAD_BUFFER_BUFFER]->Push(UploadBuffer);
	//	_UploadBuffers[UPLOAD_BUFFER_BUFFER * UPLOAD_BUFFER_PER_HEAP + UploadBufferIndex] = UploadBuffer;
	//}
	//for (uint32_t UploadBufferIndex = 0; UploadBufferIndex < UPLOAD_BUFFER_PER_HEAP; ++UploadBufferIndex)
	//{
	//	swprintf(UploadBufferName, ETERNAL_ARRAYSIZE(UploadBufferName), L"Upload Texture %d", UploadBufferIndex);
	//	//_In_ Device& DeviceObj, _In_ Heap& HeapObj, _In_ const wchar_t* Name, _In_ const ResourceDimension& Dimension, _In_ const Format& FormatObj, const TextureType& Type, _In_ uint32_t Width, _In_ uint32_t Height, _In_ uint32_t Depth, _In_ uint32_t MipCount, _In_ const TransitionState& InitialState
	//	Resource* UploadBuffer		= CreateResource(DeviceObj, *_UploadHeaps[UPLOAD_BUFFER_TEXTURE], UploadBufferName, RESOURCE_DIMENSION_TEXTURE_2D, FORMAT_BGRA8888, TEXTURE_COPY_READ, 1024, 1024, 1, 1, TRANSITION_PREINITIALIZED);
	//	GetArray()[UPLOAD_BUFFER_TEXTURE]->Push(UploadBuffer);
	//	_UploadBuffers[UPLOAD_BUFFER_TEXTURE * UPLOAD_BUFFER_PER_HEAP + UploadBufferIndex] = UploadBuffer;
	//}
}
