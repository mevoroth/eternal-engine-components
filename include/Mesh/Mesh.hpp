#pragma once

#include "Transform/Transform.hpp"
#include <vector>
#include <string>
#include <array>

namespace Eternal
{
	namespace Components
	{
		using namespace std;

		enum class TextureType
		{
			TEXTURE_TYPE_DIFFUSE	= 0,
			TEXTURE_TYPE_NORMAL,
			TEXTURE_TYPE_ROUGHNESS,
			TEXTURE_TYPE_METALLIC,
			TEXTURE_TYPE_SPECULAR,
			TEXTURE_TYPE_COUNT
		};

		class Mesh
		{
		public:

			virtual bool IsValidNode() const = 0;
			virtual bool IsValid() const = 0;
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

			void SetName(_In_ const string& InName)
			{
				_Name = InName;
			}

			void SetTexture(_In_ const TextureType& InTextureType, _In_ const string& InTextureKey)
			{
				_Maps[static_cast<uint32_t>(InTextureType)] = InTextureKey;
			}

		protected:
			vector<Mesh*>															_SubMeshes;
			Transform																_Transform;
			string																	_Name;
			array<string, static_cast<uint32_t>(TextureType::TEXTURE_TYPE_COUNT)>	_Maps;
		};
	}
}
