#pragma once

#include "GraphicData/GlobalResources.hpp"

namespace Eternal
{
	namespace GraphicData
	{
		class GlobalResourcesPBR : public GlobalResources
		{
		public:

			static constexpr int32_t SkyCubeMapSize = 256;

			GlobalResourcesPBR(_In_ GraphicsContext& InContext);
			~GlobalResourcesPBR();

			virtual bool BeginRender(_In_ GraphicsContext& InContext, _In_ System& InSystem) override;

		};
	}
}
