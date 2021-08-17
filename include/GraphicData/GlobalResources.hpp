#pragma once

#include "Graphics/GraphicsInclude.hpp"

namespace Eternal
{
	namespace Core
	{
		class System;
	}

	namespace GraphicData
	{
		using namespace Eternal::Graphics;
		using namespace Eternal::Core;

		class RenderTargetTexture;

		class GlobalResources
		{
		public:

			GlobalResources(_In_ GraphicsContext& InContext);
			~GlobalResources();

			bool BeginRender(_In_ GraphicsContext& InContext, _In_ System& InSystem);

			RenderTargetTexture& GetGBufferLuminance()
			{
				ETERNAL_ASSERT(_GBufferLuminance);
				return *_GBufferLuminance;
			}

			RenderTargetTexture& GetGBufferAlbedo()
			{
				ETERNAL_ASSERT(_GBufferAlbedo);
				return *_GBufferAlbedo;
			}

			RenderTargetTexture& GetGBufferNormals()
			{
				ETERNAL_ASSERT(_GBufferNormals);
				return *_GBufferNormals;
			}

			RenderTargetTexture& GetGBufferRoughnessMetallicSpecular()
			{
				ETERNAL_ASSERT(_GBufferRoughnessMetallicSpecular);
				return *_GBufferRoughnessMetallicSpecular;
			}

			RenderTargetTexture& GetGBufferDepthStencil()
			{
				ETERNAL_ASSERT(_GBufferDepthStencil);
				return *_GBufferDepthStencil;
			}

			View* GetViewConstantBufferView()
			{
				ETERNAL_ASSERT(_ViewConstantBufferView);
				return *_ViewConstantBufferView;
			}

		private:

			MultiBuffered<Resource>*	_ViewConstantBuffer					= nullptr;
			MultiBuffered<View>*		_ViewConstantBufferView				= nullptr;
			RenderTargetTexture*		_GBufferLuminance					= nullptr;
			RenderTargetTexture*		_GBufferAlbedo						= nullptr;
			RenderTargetTexture*		_GBufferNormals						= nullptr;
			RenderTargetTexture*		_GBufferRoughnessMetallicSpecular	= nullptr;
			RenderTargetTexture*		_GBufferDepthStencil				= nullptr;
		};
	}
}
