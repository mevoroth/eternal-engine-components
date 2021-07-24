#pragma once

#include "Transform/Transform.hpp"
#include <vector>
#include <string>
#include <array>

namespace Eternal
{
	namespace Graphics
	{
		class Resource;
		class View;
	}

	namespace Components
	{
		using namespace std;
		using namespace Eternal::Graphics;

		enum class TextureType
		{
			TEXTURE_TYPE_DIFFUSE	= 0,
			TEXTURE_TYPE_NORMAL,
			TEXTURE_TYPE_ROUGHNESS,
			TEXTURE_TYPE_METALLIC,
			TEXTURE_TYPE_SPECULAR,
			TEXTURE_TYPE_COUNT
		};

		using MeshTextures = array<string, static_cast<uint32_t>(TextureType::TEXTURE_TYPE_COUNT)>;

		struct GPUMesh
		{
			struct PerDrawInformation
			{
				uint32_t Offset					= 0;
				uint32_t IndicesCount			= 0;
				View* PerDrawConstantBufferVS	= nullptr;
			};

			vector<PerDrawInformation> PerDrawInformations;
			Resource* MeshVertexBuffer		= nullptr;
			Resource* MeshIndexBuffer		= nullptr;
			Resource* MeshConstantBuffer	= nullptr;
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

			void SetPerDrawConstantBufferViewVS(_In_ uint32_t InSubMeshIndex, _In_ View* InConstantBuffer);
			void SetMeshVertexBuffer(_In_ Resource* InVertexBuffer) { _GPUMesh.MeshVertexBuffer = InVertexBuffer; }
			void SetMeshIndexBuffer(_In_ Resource* InIndexBuffer) { _GPUMesh.MeshIndexBuffer = InIndexBuffer; }
			void SetMeshConstantBuffer(_In_ Resource* InMeshConstantBuffer) { _GPUMesh.MeshConstantBuffer = InMeshConstantBuffer; }
			const string& GetName() const { return _Name; }
			void SetName(_In_ const string& InName) { _Name = InName; }

			//void SetTexture(_In_ const TextureType& InTextureType, _In_ const string& InTextureKey)
			//{
			//	_Maps[static_cast<uint32_t>(InTextureType)] = InTextureKey;
			//}

		protected:
			GPUMesh					_GPUMesh;
			string					_Name;
			vector<MeshTextures>	_Maps;
		};

		class MeshCollection
		{
		public:

			~MeshCollection();

			vector<Mesh*> Meshes;
		};
	}
}
