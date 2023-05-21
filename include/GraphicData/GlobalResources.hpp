#pragma once

#include "Graphics/GraphicsInclude.hpp"
#include "HLSLPerViewConstants.hpp"
#include "HLSLAtmosphereConstants.hpp"

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

		class GlobalResources
		{
		public:

			static constexpr int32_t SkyCubeMapSize = 256;

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

			RenderTargetTexture& GetSky()
			{
				ETERNAL_ASSERT(_Sky);
				return *_Sky;
			}

			View* GetViewConstantBufferView()
			{
				return _ViewConstantBuffer.GetView();
			}

			View* GetShadowMapViewConstantBufferView()
			{
				return _ShadowMapViewConstantBuffer.GetView();
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

			View* GetAtmosphereConstantBufferView()
			{
				return _AtmosphereConstantBuffer.GetView();
			}

			Resource& GetAtmosphereConstantBuffer()
			{
				return **_AtmosphereConstantBuffer.ResourceBuffer;
			}

			View* GetSkyViewCubeMapConstantBufferView()
			{
				return _SkyViewCubeMapConstantBuffer.GetView();
			}

			Resource& GetSkyViewCubeMapConstantBuffer()
			{
				return **_SkyViewCubeMapConstantBuffer.ResourceBuffer;
			}

			const Viewport& GetSkyViewport() const
			{
				ETERNAL_ASSERT(_SkyViewport);
				return *_SkyViewport;
			}

		private:

			ConstantBuffer<PerViewConstants>		_ViewConstantBuffer;
			RenderTargetTexture*					_GBufferLuminance					= nullptr;
			RenderTargetTexture*					_GBufferAlbedo						= nullptr;
			RenderTargetTexture*					_GBufferNormals						= nullptr;
			RenderTargetTexture*					_GBufferRoughnessMetallicSpecular	= nullptr;
			RenderTargetTexture*					_GBufferDepthStencil				= nullptr;
			
			ConstantBuffer<PerViewConstants>		_ShadowMapViewConstantBuffer;
			RenderTargetTexture*					_ShadowMap							= nullptr;
			Viewport*								_ShadowMapViewport					= nullptr;

			ConstantBuffer<AtmosphereConstants>		_AtmosphereConstantBuffer;
			ConstantBuffer<PerViewCubeMapConstants>	_SkyViewCubeMapConstantBuffer;
			RenderTargetTexture*					_Sky								= nullptr;
			Viewport*								_SkyViewport						= nullptr;
		};
	}
}
