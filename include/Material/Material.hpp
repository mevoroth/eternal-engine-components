#pragma once

#include <vector>

namespace Eternal
{
	namespace Graphics
	{
		class DescriptorTable;
	}

	namespace GraphicData
	{
		class Texture;
	}

	namespace Components
	{
		using namespace std;
		using namespace Eternal::GraphicData;
		using namespace Eternal::Graphics;

		enum class TextureType
		{
			TEXTURE_TYPE_DIFFUSE	= 0,
			TEXTURE_TYPE_NORMAL,
			TEXTURE_TYPE_ROUGHNESS_METALLIC_SPECULAR,
			TEXTURE_TYPE_COUNT
		};

		class Material
		{
		public:

			Material();

			void SetTexture(_In_ uint32_t InSlotIndex, _In_ Texture* InTexture);
			void CommitMaterial(_Inout_ DescriptorTable& InOutDescriptorTable);

		private:

			vector<Texture*> _Textures;
		};
	}
}