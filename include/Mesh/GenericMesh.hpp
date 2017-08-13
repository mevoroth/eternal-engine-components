#ifndef _GENERIC_MESH_HPP_
#define _GENERIC_MESH_HPP_

#include <cstdint>
#include <vector>

#include "Macros/Macros.hpp"
#include "Mesh/Mesh.hpp"
#include "Transform/Transform.hpp"
//#include "Graphics/VertexBuffer.hpp"
//#include "Graphics/VertexBufferFactory.hpp"
//#include "Graphics/IndexBuffer.hpp"
//#include "Graphics/IndexBufferFactory.hpp"
#include "Graphics/ResourceFactory.hpp"
#include "Graphics/HeapFactory.hpp"
#include "Graphics/Heap.hpp"
#include "Graphics/CommandList.hpp"
#include "NextGenGraphics/Resource.hpp"
#include "GraphicData/UploadBuffers.hpp"

using namespace std;

namespace Eternal
{
	namespace Components
	{
		template<class VertexT, typename IndexT = uint32_t>
		class GenericMesh : public Mesh
		{
		public:
			void PushVertex(_In_ const VertexT& V)
			{
				_Vertices.push_back(V);
			}

			void PushTriangle(_In_ IndexT V0, _In_ IndexT V1, _In_ IndexT V2)
			{
				_Indices.push_back(V0);
				_Indices.push_back(V1);
				_Indices.push_back(V2);
			}

			inline VertexT& GetVertex(_In_ uint32_t VertexIndex)
			{
				ETERNAL_ASSERT(VertexIndex < GetVerticesCount());
				return _Vertices[VertexIndex];
			}
			inline uint32_t GetVerticesCount()
			{
				return (uint32_t)_Vertices.size();
			}

			virtual Resource* GetVerticesBuffer() override
			{
				return _VerticesBuffer;
			}

			virtual Resource* GetIndicesBuffer() override
			{
				return _IndicesBuffer;
			}

			virtual uint32_t GetVerticesCount() const override
			{
				return _Vertices.size();
			}

			virtual uint32_t GetIndicesCount() const override
			{
				return _Indices.size();
			}

			virtual void InitializeBuffers(_In_ Device& DeviceObj, _Inout_ CommandList& CopyCommandList, _Inout_ UploadBuffers* UploadBuffersObj) override
			{
				//if (_VerticesBuffer&&_IndicesBuffer)
				//	return;
				//ETERNAL_ASSERT(_Vertices.size());
				//ETERNAL_ASSERT(_Indices.size());
				//ETERNAL_ASSERT(!(_Indices.size() % 3));
				//ETERNAL_ASSERT(!_VerticesBuffer);
				//ETERNAL_ASSERT(!_IndicesBuffer);
				//_VerticesBuffer = CreateVertexBuffer<VertexT>(_Vertices);
				//_IndicesBuffer = CreateIndexBuffer<IndexT>(_Indices);
				InitializeMeshBuffers(DeviceObj, CopyCommandList, UploadBuffersObj);
				for (uint32_t SubMeshIndex = 0; SubMeshIndex < _SubMeshes.size(); ++SubMeshIndex)
				{
					_SubMeshes[SubMeshIndex]->InitializeMeshBuffers(DeviceObj, CopyCommandList, UploadBuffersObj);
				}

			}
			virtual void DestroyBuffers() override
			{
				//ETERNAL_ASSERT(_VerticesBuffer);
				//ETERNAL_ASSERT(_IndicesBuffer);
				//delete _VerticesBuffer;
				//_VerticesBuffer = nullptr;
				//delete _IndicesBuffer;
				//_IndicesBuffer = nullptr;

				delete _VerticesBuffer;
				_VerticesBuffer = nullptr;

				delete _IndicesBuffer;
				_IndicesBuffer = nullptr;

				delete _VerticesHeap;
				_VerticesHeap = nullptr;

				delete _IndicesHeap;
				_IndicesHeap = nullptr;
			}

			virtual bool IsValidNode() const override
			{
				return _Vertices.size() > 0;
			}
			virtual bool IsValid() const override
			{
				if (_Vertices.size() > 0)
				{
					return true;
				}
				for (uint32_t SubMeshIndex = 0; SubMeshIndex < _SubMeshes.size(); ++SubMeshIndex)
				{
					if (_SubMeshes[SubMeshIndex]->IsValid())
					{
						return true;
					}
				}
				return false;
			}

			virtual void InitializeMeshBuffers(_In_ Device& DeviceObj, _Inout_ CommandList& CopyCommandList, _Inout_ UploadBuffers* UploadBuffersObj) override
			{
				if (!(_Indices.size() || _Vertices.size()))
					return;

				size_t IndicesBufferSize = _Indices.size() * sizeof(IndexT);
				size_t VerticesBufferSize = _Vertices.size() * sizeof(VertexT);

				_IndicesHeap	= CreateHeap(DeviceObj, HEAP_TYPE_BUFFER, 1, true, false, false, false);
				_VerticesHeap	= CreateHeap(DeviceObj, HEAP_TYPE_BUFFER, 1, true, false, false, false);
				_IndicesBuffer	= CreateResource(DeviceObj, *_IndicesHeap,	L"Indices Buffer",	sizeof(IndexT),		IndicesBufferSize,	BUFFER_INDEX);
				_VerticesBuffer = CreateResource(DeviceObj, *_VerticesHeap,	L"Vertices Buffer",	sizeof(VertexT),	VerticesBufferSize, BUFFER_VERTEX);

				Resource* UploadBuffer = UploadBuffersObj->Get(UPLOAD_BUFFER_BUFFER)->Pop();
				void* Data = UploadBuffer->Map(DeviceObj);
				memcpy(Data, _Indices.data(), IndicesBufferSize);
				UploadBuffer->Unmap(DeviceObj);

				CopyCommandList.CopyBuffer(*UploadBuffer, *_IndicesBuffer, 0ull, 0ull, IndicesBufferSize);

				UploadBuffer = UploadBuffersObj->Get(UPLOAD_BUFFER_BUFFER)->Pop();
				Data = UploadBuffer->Map(DeviceObj);
				memcpy(Data, _Vertices.data(), VerticesBufferSize);
				UploadBuffer->Unmap(DeviceObj);

				CopyCommandList.CopyBuffer(*UploadBuffer, *_VerticesBuffer, 0ull, 0ull, VerticesBufferSize);

				ResourceTransition Transitions[] =
				{
					ResourceTransition(_IndicesBuffer, TRANSITION_COPY_WRITE, TRANSITION_INDEX_READ),
					ResourceTransition(_VerticesBuffer, TRANSITION_COPY_WRITE, TRANSITION_VERTEX_ATTRIBUTE_READ)
				};

				CopyCommandList.Transition(Transitions, ETERNAL_ARRAYSIZE(Transitions), nullptr, 0u);
			}

		private:
			vector<IndexT>	_Indices;
			vector<VertexT>	_Vertices;
			Heap*			_IndicesHeap	= nullptr;
			Heap*			_VerticesHeap	= nullptr;
			Resource*		_IndicesBuffer	= nullptr;
			Resource*		_VerticesBuffer	= nullptr;
		};
	}
}

#endif
