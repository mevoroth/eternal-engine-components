#pragma once

#include "Graphics/GraphicsInclude.hpp"
#include "HLSLPerViewConstants.hpp"

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
		using namespace Eternal::HLSL;

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

			RenderTargetTexture& GetShadowMap()
			{
				ETERNAL_ASSERT(_ShadowMap);
				return *_ShadowMap;
			}

			View* GetViewConstantBufferView()
			{
				return *_ViewConstantBuffer.ResourceView;
			}

			View* GetShadowMapViewConstantBufferView()
			{
				return *_ShadowMapViewConstantBuffer.ResourceView;
			}

			Resource& GetShadowMapViewConstantBuffer()
			{
				return **_ShadowMapViewConstantBuffer.ResourceBuffer;
			}

			const Viewport& GetShadowMapViewport() const
			{
				ETERNAL_ASSERT(_ShadowMapViewport);
				return *_ShadowMapViewport;
			}

		private:

			ConstantBuffer<PerViewConstants>	_ViewConstantBuffer;
			RenderTargetTexture*				_GBufferLuminance					= nullptr;
			RenderTargetTexture*				_GBufferAlbedo						= nullptr;
			RenderTargetTexture*				_GBufferNormals						= nullptr;
			RenderTargetTexture*				_GBufferRoughnessMetallicSpecular	= nullptr;
			RenderTargetTexture*				_GBufferDepthStencil				= nullptr;
			
			ConstantBuffer<PerViewConstants>	_ShadowMapViewConstantBuffer;
			RenderTargetTexture*				_ShadowMap							= nullptr;
			Viewport*							_ShadowMapViewport					= nullptr;
		};
	}
}
