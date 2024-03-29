#pragma once

#include "Material/MaterialType.hpp"
#include <vector>

namespace Eternal
{
	namespace Graphics
	{
		class DescriptorTable;
		class Texture;
	}

	namespace Components
	{
		using namespace std;
		using namespace Eternal::Graphics;

		enum class TextureType
		{
			TEXTURE_TYPE_DIFFUSE	= 0,
			TEXTURE_TYPE_NORMAL,
			TEXTURE_TYPE_ROUGHNESS_METALLIC_SPECULAR,
			TEXTURE_TYPE_COUNT,
			TEXTURE_TYPE_INVALID	= ~0
		};

		class Material
		{
		public:

			static Material* DefaultMaterial;

			Material();

			bool IsValid(_In_ TextureType InSlotIndex) const;
			void SetTexture(_In_ TextureType InSlotIndex, _In_ Texture* InTexture);
			void CommitMaterial(_Inout_ DescriptorTable& InOutDescriptorTable);
			MaterialType& GetMaterialType() { return _MaterialType; }
			void SetMaterialType(const MaterialType& InMaterialType) { _MaterialType = InMaterialType; }

		private:

			vector<Texture*>	_Textures;
			MaterialType		_MaterialType	= MaterialType::MATERIAL_TYPE_OPAQUE;
		};
	}
}
