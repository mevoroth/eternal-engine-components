#include "Material/Material.hpp"
#include "Graphics/GraphicsInclude.hpp"
#include "GraphicData/Texture.hpp"

namespace Eternal
{
	namespace Components
	{
		Material::Material()
		{
			_Textures.resize(static_cast<size_t>(TextureType::TEXTURE_TYPE_COUNT));
		}

		void Material::SetTexture(_In_ TextureType InSlotIndex, _In_ Texture* InTexture)
		{
			uint32_t SlotIndexInt = static_cast<uint32_t>(InSlotIndex);
			ETERNAL_ASSERT(SlotIndexInt < _Textures.size());
			ETERNAL_ASSERT(InTexture);
			_Textures[SlotIndexInt] = InTexture;
		}

		void Material::CommitMaterial(_Inout_ DescriptorTable& InOutDescriptorTable)
		{
			for (uint32_t TextureIndex = 0; TextureIndex < static_cast<uint32_t>(TextureType::TEXTURE_TYPE_COUNT); ++TextureIndex)
				InOutDescriptorTable.SetDescriptor(4 + TextureIndex, _Textures[TextureIndex]->GetShaderResourceView());
		}
	}
}
