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

		class Mesh
		{
		public:
			virtual VertexBuffer* GetVertexBuffer() = 0;
			virtual IndexBuffer* GetIndexBuffer() = 0;

			virtual Transform& GetTransform() = 0;
			virtual const Transform& GetTransform() const = 0;

			virtual Mesh& GetSubMesh(uint32_t Index) = 0;
			virtual size_t GetSubMeshesCount() = 0;

			virtual bool IsValidNode() const = 0;
			virtual bool IsValid() const = 0;

			void SetTexture(const std::string& TextureName)
			{
				_Texture = TextureName;
			}
			std::string _Texture;

		protected:
			VertexBuffer* _VerticesBuffer = nullptr;
			IndexBuffer* _IndicesBuffer = nullptr;
		};
	}
}

#endif
