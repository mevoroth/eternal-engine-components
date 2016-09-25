#ifndef _MESH_HPP_
#define _MESH_HPP_
#include <string>
namespace Eternal
{
	namespace Graphics
	{
		class VertexBuffer;
		class IndexBuffer;
	}
	namespace Components
	{
		using namespace Eternal::Graphics;
		class Transform;
		class Bone;
		class BoundingBox;

		class Mesh
		{
		public:
			virtual void InitializeBuffers() = 0;
			virtual void DestroyBuffers() = 0;
			virtual VertexBuffer* GetVertexBuffer() = 0;
			virtual IndexBuffer* GetIndexBuffer() = 0;

			virtual Transform& GetTransform() = 0;
			virtual const Transform& GetTransform() const = 0;

			virtual Mesh& GetSubMesh(_In_ uint32_t Index) = 0;
			virtual size_t GetSubMeshesCount() = 0;

			virtual bool IsValidNode() const = 0;
			virtual bool IsValid() const = 0;

			void SetTexture(const std::string& TextureName)
			{
				_Texture = TextureName;
			}
			std::string _Texture;

			void SetBone(_In_ Bone* BoneObj);
			Bone* GetBone();

			void SetBoundingBox(_In_ BoundingBox* BoundingBoxObj);
			BoundingBox* GetBoundingBox();

			void SetBBMesh(Mesh* MeshObj);
			Mesh* GetBBMesh();

		protected:
			VertexBuffer* _VerticesBuffer = nullptr;
			IndexBuffer* _IndicesBuffer = nullptr;
			Mesh* _BBMesh = nullptr;
			//VertexBuffer* _BoundingBoxVerticesBuffer = nullptr;
			//IndexBuffer* _BoundingBoxIndicesBuffer = nullptr;
			Bone* _Bone = nullptr;
			BoundingBox* _BoundingBox = nullptr;
		};
	}
}

#endif
