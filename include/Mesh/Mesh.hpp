#pragma once

#include "Transform/Transform.hpp"
#include <vector>
#include <string>

namespace Eternal
{
	namespace Graphics
	{
		class Resource;
		class View;
	}
	
	namespace FileSystem
	{
		class File;
	}

	namespace Components
	{
		using namespace std;
		using namespace Eternal::Graphics;

		class Material;

		struct GPUMesh
		{
			struct PerDrawInformation
			{
				uint32_t IndicesOffset			= 0;
				uint32_t IndicesCount			= 0;
				uint32_t VerticesOffset			= 0;
				View* PerDrawConstantBufferMSVS	= nullptr;
				Material* PerDrawMaterial		= nullptr;
			};

			vector<PerDrawInformation> PerDrawInformations;
			Resource* MeshVertexBuffer				= nullptr;
			Resource* MeshIndexBuffer				= nullptr;
			Resource* MeshConstantBuffer			= nullptr;
			View* MeshVertexStructuredBufferView	= nullptr;
			View* MeshIndexStructuredBufferView		= nullptr;
		};

		class Mesh
		{
		public:

			virtual ~Mesh() {}

			virtual uint32_t GetVerticesCount() const = 0;
			virtual uint32_t GetIndicesCount() const = 0;
			virtual uint32_t GetConstantBufferCount() const = 0;
			virtual uint32_t GetVertexStride() const = 0;
			virtual uint32_t GetIndexStride() const = 0;
			virtual uint32_t GetConstantBufferStride() const = 0;
			virtual uint32_t GetIndicesMaxCount() const = 0;
			virtual const void* GetVerticesData() const = 0;
			virtual const void* GetIndicesData() const = 0;
			virtual const void* GetConstantBufferData() const = 0;

			void SetPerDrawConstantBufferViewMSVS(_In_ uint32_t InSubMeshIndex, _In_ View* InConstantBuffer);
			void SetMeshVertexBuffer(_In_ Resource* InVertexBuffer) { _GPUMesh.MeshVertexBuffer = InVertexBuffer; }
			void SetMeshVertexStructuredBufferView(_In_ View* InVertexStructuredBufferView) { _GPUMesh.MeshVertexStructuredBufferView = InVertexStructuredBufferView; }
			void SetMeshIndexBuffer(_In_ Resource* InIndexBuffer) { _GPUMesh.MeshIndexBuffer = InIndexBuffer; }
			void SetMeshIndexStructuredBufferView(_In_ View* InIndexStructuredBufferView) { _GPUMesh.MeshIndexStructuredBufferView = InIndexStructuredBufferView; }
			void SetMeshConstantBuffer(_In_ Resource* InMeshConstantBuffer) { _GPUMesh.MeshConstantBuffer = InMeshConstantBuffer; }
			const string& GetName() const { return _Name; }
			void SetName(_In_ const string& InName) { _Name = InName; }
			GPUMesh& GetGPUMesh() { return _GPUMesh; }

		protected:
			GPUMesh					_GPUMesh;
			string					_Name;
		};

		class MeshCollection
		{
		public:

			~MeshCollection();

			vector<Mesh*> Meshes;
		};
	}
}
