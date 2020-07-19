#ifndef _MESH_HPP_
#define _MESH_HPP_

#include <string>
#include "Transform/Transform.hpp"

namespace Eternal
{
	namespace Graphics
	{
		class Device;
		class CommandList;
		class Resource;
	}

	namespace GraphicData
	{
		class UploadBuffers;
	}

	namespace Components
	{
		using namespace std;
		using namespace Eternal::Graphics;
		using namespace Eternal::GraphicData;
		class Bone;
		class BoundingBox;

		class Mesh
		{
		public:
			virtual void InitializeBuffers(_In_ Device& DeviceObj, _Inout_ CommandList& CopyCommandList, _Inout_ UploadBuffers* UploadBufferObj) = 0;
			virtual void DestroyBuffers() = 0;
			virtual bool IsValidNode() const = 0;
			virtual bool IsValid() const = 0;
			virtual Resource* GetVerticesBuffer() = 0;
			virtual Resource* GetIndicesBuffer() = 0;
			virtual uint32_t GetVerticesCount() const = 0;
			virtual uint32_t GetIndicesCount() const = 0;

			Transform& GetTransform()
			{
				return _Transform;
			}
			const Transform& GetTransform() const
			{
				return _Transform;
			}

			Mesh& GetSubMesh(_In_ uint32_t Index)
			{
				ETERNAL_ASSERT(Index < _SubMeshes.size());
				return *_SubMeshes[Index];
			}
			size_t GetSubMeshesCount()
			{
				return _SubMeshes.size();
			}

			void PushMesh(_In_ Mesh* SubMesh)
			{
				_SubMeshes.push_back(SubMesh);
			}

			virtual void InitializeMeshBuffers(_In_ Device& DeviceObj, _Inout_ CommandList& CopyCommandList, _Inout_ UploadBuffers* UploadBufferObj) = 0;

			vector<Mesh*>	_SubMeshes;
			Transform		_Transform;
		};

		//class Mesh
		//{
		//public:
		//	virtual void InitializeBuffers() = 0;
		//	virtual void DestroyBuffers() = 0;
		//	VertexBuffer* GetVertexBuffer()
		//	{
		//		return _VerticesBuffer;
		//	}
		//	IndexBuffer* GetIndexBuffer()
		//	{
		//		return _IndicesBuffer;
		//	}

		//	Transform& GetTransform()
		//	{
		//		return _Transform;
		//	}
		//	const Transform& GetTransform() const
		//	{
		//		return _Transform;
		//	}

		//	Mesh& GetSubMesh(_In_ uint32_t Index)
		//	{
		//		ETERNAL_ASSERT(Index < _SubMeshes.size());
		//		return *_SubMeshes[Index];
		//	}
		//	size_t GetSubMeshesCount()
		//	{
		//		return _SubMeshes.size();
		//	}

		//	void PushMesh(_In_ Mesh* SubMesh)
		//	{
		//		_SubMeshes.push_back(SubMesh);
		//	}

		//	virtual bool IsValidNode() const = 0;
		//	virtual bool IsValid() const = 0;

		//	// DIRTY BELOW
		//	void SetTexture(Texture* Diffuse, Texture* Specular, Texture* Normal)
		//	{
		//		_Diffuse = Diffuse;
		//		_Specular = Specular;
		//		_Normal = Normal;
		//	}
		//	Texture* _Diffuse;
		//	Texture* _Specular;
		//	Texture* _Normal;

		//	void SetBone(_In_ Bone* BoneObj);
		//	Bone* GetBone();

		//	void SetBoundingBox(_In_ BoundingBox* BoundingBoxObj);
		//	BoundingBox* GetBoundingBox();

		//	void SetBBMesh(Mesh* MeshObj);
		//	Mesh* GetBBMesh();

		//protected:
		//	Transform _Transform;

		//	VertexBuffer* _VerticesBuffer = nullptr;
		//	IndexBuffer* _IndicesBuffer = nullptr;

		//	vector<Mesh*> _SubMeshes;
		//	
		//	// DIRTY BELOW
		//	Mesh* _BBMesh = nullptr;
		//	//VertexBuffer* _BoundingBoxVerticesBuffer = nullptr;
		//	//IndexBuffer* _BoundingBoxIndicesBuffer = nullptr;
		//	Bone* _Bone = nullptr;
		//	BoundingBox* _BoundingBox = nullptr;
		//};
	}
}

#endif
