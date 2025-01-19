#pragma once

#include "Graphics/GraphicsInclude.hpp"
#include "ShadersReflection/HLSLPerViewConstants.hpp"
#include "ShadersReflection/HLSLAtmosphereConstants.hpp"

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

			virtual ~GlobalResources();

			virtual bool BeginRender(_In_ GraphicsContext& InContext, _In_ System& InSystem);

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
				ETERNAL_ASSERT(_ShadowMapViewConstantBuffer);
				return _ShadowMapViewConstantBuffer->GetView();
			}

			Resource& GetShadowMapViewConstantBuffer()
			{
				ETERNAL_ASSERT(_ShadowMapViewConstantBuffer);
				return *_ShadowMapViewConstantBuffer->GetResource();
			}

			const Viewport& GetShadowMapViewport() const
			{
				ETERNAL_ASSERT(_ShadowMapViewport);
				return *_ShadowMapViewport;
			}

			View* GetAtmosphereConstantBufferView()
			{
				ETERNAL_ASSERT(_AtmosphereConstantBuffer);
				return _AtmosphereConstantBuffer->GetView();
			}

			Resource& GetAtmosphereConstantBuffer()
			{
				ETERNAL_ASSERT(_AtmosphereConstantBuffer);
				return *_AtmosphereConstantBuffer->GetResource();
			}

			View* GetSkyViewCubeMapConstantBufferView()
			{
				ETERNAL_ASSERT(_SkyViewCubeMapConstantBuffer);
				return _SkyViewCubeMapConstantBuffer->GetView();
			}

			Resource& GetSkyViewCubeMapConstantBuffer()
			{
				ETERNAL_ASSERT(_SkyViewCubeMapConstantBuffer);
				return *_SkyViewCubeMapConstantBuffer->GetResource();
			}

			const Viewport& GetSkyViewport() const
			{
				ETERNAL_ASSERT(_SkyViewport);
				return *_SkyViewport;
			}

			const vector<View*>& GetSkyMipShaderResourceViews() const
			{
				return _SkyMipShaderResourceViews;
			}

			const vector<View*>& GetSkyMipUnorderedAccessViews() const
			{
				return _SkyMipUnorderedAccessViews;
			}

		protected:

			GlobalResources(_In_ GraphicsContext& InContext);

			ConstantBuffer<PerViewConstants>			_ViewConstantBuffer;
			RenderTargetTexture*						_GBufferLuminance					= nullptr;
			RenderTargetTexture*						_GBufferDepthStencil				= nullptr;
			RenderTargetTexture*						_GBufferAlbedo						= nullptr;
			RenderTargetTexture*						_GBufferNormals						= nullptr;
			RenderTargetTexture*						_GBufferRoughnessMetallicSpecular	= nullptr;
			
			ConstantBuffer<PerViewConstants>*			_ShadowMapViewConstantBuffer		= nullptr;
			RenderTargetTexture*						_ShadowMap							= nullptr;
			Viewport*									_ShadowMapViewport					= nullptr;

			ConstantBuffer<AtmosphereConstants>*		_AtmosphereConstantBuffer			= nullptr;
			ConstantBuffer<PerViewCubeMapConstants>*	_SkyViewCubeMapConstantBuffer		= nullptr;
			RenderTargetTexture*						_Sky								= nullptr;
			Viewport*									_SkyViewport						= nullptr;
			vector<View*>								_SkyMipShaderResourceViews;
			vector<View*>								_SkyMipUnorderedAccessViews;
		};
	}
}
