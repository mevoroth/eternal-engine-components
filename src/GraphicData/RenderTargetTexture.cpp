#include "GraphicData/RenderTargetTexture.hpp"
#include "Graphics/GraphicsInclude.hpp"

namespace Eternal
{
	namespace GraphicData
	{
		static constexpr ViewShaderResourceType VIEW_SHADER_RESOURCE_TYPES[] =
		{
			ViewShaderResourceType::VIEW_SHADER_RESOURCE_UNKNOWN,
			ViewShaderResourceType::VIEW_SHADER_RESOURCE_BUFFER,
			ViewShaderResourceType::VIEW_SHADER_RESOURCE_TEXTURE_1D,
			ViewShaderResourceType::VIEW_SHADER_RESOURCE_TEXTURE_1D_ARRAY,
			ViewShaderResourceType::VIEW_SHADER_RESOURCE_TEXTURE_2D,
			ViewShaderResourceType::VIEW_SHADER_RESOURCE_TEXTURE_2D_ARRAY,
			ViewShaderResourceType::VIEW_SHADER_RESOURCE_TEXTURE_3D,
			ViewShaderResourceType::VIEW_SHADER_RESOURCE_TEXTURE_CUBE,
			ViewShaderResourceType::VIEW_SHADER_RESOURCE_TEXTURE_CUBE_ARRAY
		};
		ETERNAL_STATIC_ASSERT(ETERNAL_ARRAYSIZE(VIEW_SHADER_RESOURCE_TYPES) == static_cast<uint32_t>(ResourceDimension::RESOURCE_DIMENSION_COUNT), "Mismatch between resource dimension and view shader resource types");

		static constexpr ViewRenderTargetType VIEW_RENDER_TARGET_TYPES[] =
		{
			ViewRenderTargetType::VIEW_RENDER_TARGET_UNKNOWN,
			ViewRenderTargetType::VIEW_RENDER_TARGET_BUFFER,
			ViewRenderTargetType::VIEW_RENDER_TARGET_TEXTURE_1D,
			ViewRenderTargetType::VIEW_RENDER_TARGET_TEXTURE_1D_ARRAY,
			ViewRenderTargetType::VIEW_RENDER_TARGET_TEXTURE_2D,
			ViewRenderTargetType::VIEW_RENDER_TARGET_TEXTURE_2D_ARRAY,
			ViewRenderTargetType::VIEW_RENDER_TARGET_TEXTURE_3D,
			ViewRenderTargetType::VIEW_RENDER_TARGET_TEXTURE_2D_ARRAY,
			ViewRenderTargetType::VIEW_RENDER_TARGET_TEXTURE_2D_ARRAY
		};
		ETERNAL_STATIC_ASSERT(ETERNAL_ARRAYSIZE(VIEW_RENDER_TARGET_TYPES) == static_cast<uint32_t>(ResourceDimension::RESOURCE_DIMENSION_COUNT), "Mismatch between resource dimension and view render target types");

		static constexpr ViewUnorderedAccessType VIEW_UNORDERED_ACCESS_TYPES[] =
		{
			ViewUnorderedAccessType::VIEW_UNORDERED_ACCESS_UNKNOWN,
			ViewUnorderedAccessType::VIEW_UNORDERED_ACCESS_BUFFER,
			ViewUnorderedAccessType::VIEW_UNORDERED_ACCESS_TEXTURE_1D,
			ViewUnorderedAccessType::VIEW_UNORDERED_ACCESS_TEXTURE_1D_ARRAY,
			ViewUnorderedAccessType::VIEW_UNORDERED_ACCESS_TEXTURE_2D,
			ViewUnorderedAccessType::VIEW_UNORDERED_ACCESS_TEXTURE_2D_ARRAY,
			ViewUnorderedAccessType::VIEW_UNORDERED_ACCESS_TEXTURE_3D,
			ViewUnorderedAccessType::VIEW_UNORDERED_ACCESS_TEXTURE_2D_ARRAY,
			ViewUnorderedAccessType::VIEW_UNORDERED_ACCESS_TEXTURE_2D_ARRAY
		};
		ETERNAL_STATIC_ASSERT(ETERNAL_ARRAYSIZE(VIEW_UNORDERED_ACCESS_TYPES) == static_cast<uint32_t>(ResourceDimension::RESOURCE_DIMENSION_COUNT), "Mismatch between resource dimension and view unordered access types");

		static constexpr ViewDepthStencilType VIEW_DEPTH_STENCIL_TYPES[] =
		{
			ViewDepthStencilType::VIEW_DEPTH_STENCIL_TEXTURE_1D,
			ViewDepthStencilType::VIEW_DEPTH_STENCIL_TEXTURE_1D,
			ViewDepthStencilType::VIEW_DEPTH_STENCIL_TEXTURE_1D,
			ViewDepthStencilType::VIEW_DEPTH_STENCIL_TEXTURE_1D_ARRAY,
			ViewDepthStencilType::VIEW_DEPTH_STENCIL_TEXTURE_2D,
			ViewDepthStencilType::VIEW_DEPTH_STENCIL_TEXTURE_2D_ARRAY,
			ViewDepthStencilType::VIEW_DEPTH_STENCIL_TEXTURE_2D_ARRAY,
			ViewDepthStencilType::VIEW_DEPTH_STENCIL_TEXTURE_2D_ARRAY,
			ViewDepthStencilType::VIEW_DEPTH_STENCIL_TEXTURE_2D_ARRAY
		};
		ETERNAL_STATIC_ASSERT(ETERNAL_ARRAYSIZE(VIEW_UNORDERED_ACCESS_TYPES) == static_cast<uint32_t>(ResourceDimension::RESOURCE_DIMENSION_COUNT), "Mismatch between resource dimension and view depth stencil types");

		ViewShaderResourceType ConvertResourceDimensionToViewShaderResourceType(_In_ const ResourceDimension& InResourceDimension)
		{
			return VIEW_SHADER_RESOURCE_TYPES[static_cast<uint32_t>(InResourceDimension)];
		}

		ViewRenderTargetType ConvertResourceDimensionToViewRenderTargetType(_In_ const ResourceDimension& InResourceDimension)
		{
			return VIEW_RENDER_TARGET_TYPES[static_cast<uint32_t>(InResourceDimension)];
		}

		ViewUnorderedAccessType ConvertResourceDimensionToViewUnorderedAccessType(_In_ const ResourceDimension& InResourceDimension)
		{
			return VIEW_UNORDERED_ACCESS_TYPES[static_cast<uint32_t>(InResourceDimension)];
		}

		ViewDepthStencilType ConvertResourceDimensionToViewDepthStencilType(_In_ const ResourceDimension& InResourceDimension)
		{
			return VIEW_DEPTH_STENCIL_TYPES[static_cast<uint32_t>(InResourceDimension)];
		}

		RenderTargetTexture::RenderTargetTexture(_In_ GraphicsContext& InContext, _In_ const TextureResourceCreateInformation& InTextureResourceCreateInformation, _In_ const RenderTargetTextureFlags& Flags)
		{
			ETERNAL_ASSERT(Flags == RenderTargetTextureFlags::RENDER_TARGET_TEXTURE_FLAGS_ALL
						|| Flags == RenderTargetTextureFlags::RENDER_TARGET_TEXTURE_FLAGS_GRAPHICS
						|| Flags == RenderTargetTextureFlags::RENDER_TARGET_TEXTURE_FLAGS_COMPUTE);
			_Texture = CreateTexture(InTextureResourceCreateInformation);

			if ((Flags & RenderTargetTextureFlags::RENDER_TARGET_TEXTURE_FLAGS_SHADER_RESOURCE_VIEW) == RenderTargetTextureFlags::RENDER_TARGET_TEXTURE_FLAGS_SHADER_RESOURCE_VIEW)
			{
				ViewMetaData MetaData;
				switch (InTextureResourceCreateInformation.TextureInformation.Dimension)
				{
				case ResourceDimension::RESOURCE_DIMENSION_TEXTURE_1D:
				{
					MetaData.ShaderResourceViewTexture1D.MipLevels			= InTextureResourceCreateInformation.TextureInformation.MIPLevels;
				} break;
				case ResourceDimension::RESOURCE_DIMENSION_TEXTURE_1D_ARRAY:
				{
					MetaData.ShaderResourceViewTexture1DArray.MipLevels		= InTextureResourceCreateInformation.TextureInformation.MIPLevels;
					MetaData.ShaderResourceViewTexture1DArray.ArraySize		= InTextureResourceCreateInformation.TextureInformation.DepthOrArraySize;
				} break;
				case ResourceDimension::RESOURCE_DIMENSION_TEXTURE_2D:
				{
					MetaData.ShaderResourceViewTexture2D.MipLevels			= InTextureResourceCreateInformation.TextureInformation.MIPLevels;
				} break;
				case ResourceDimension::RESOURCE_DIMENSION_TEXTURE_2D_ARRAY:
				{
					MetaData.ShaderResourceViewTexture2DArray.MipLevels		= InTextureResourceCreateInformation.TextureInformation.MIPLevels;
					MetaData.ShaderResourceViewTexture2DArray.ArraySize		= InTextureResourceCreateInformation.TextureInformation.DepthOrArraySize;
				} break;
				case ResourceDimension::RESOURCE_DIMENSION_TEXTURE_3D:
				{
					MetaData.ShaderResourceViewTexture3D.MipLevels			= InTextureResourceCreateInformation.TextureInformation.MIPLevels;
				} break;
				case ResourceDimension::RESOURCE_DIMENSION_TEXTURE_CUBE:
				{
					MetaData.ShaderResourceViewTextureCube.MipLevels		= InTextureResourceCreateInformation.TextureInformation.MIPLevels;
				} break;
				case ResourceDimension::RESOURCE_DIMENSION_TEXTURE_CUBE_ARRAY:
				{
					MetaData.ShaderResourceViewTextureCubeArray.MipLevels	= InTextureResourceCreateInformation.TextureInformation.MIPLevels;
					MetaData.ShaderResourceViewTextureCubeArray.NumCubes	= InTextureResourceCreateInformation.TextureInformation.DepthOrArraySize / 6;
				} break;
				}
				ShaderResourceViewCreateInformation TextureShaderResourceViewCreateInformation(
					InContext,
					_Texture,
					MetaData,
					ConvertDepthStencilFormatToFormat(InTextureResourceCreateInformation.TextureInformation.ResourceFormat),
					ConvertResourceDimensionToViewShaderResourceType(InTextureResourceCreateInformation.TextureInformation.Dimension)
				);
				_ShaderResourceView = CreateShaderResourceView(TextureShaderResourceViewCreateInformation);
			}

			if ((Flags & RenderTargetTextureFlags::RENDER_TARGET_TEXTURE_FLAGS_RENDER_TARGET_DEPTH_STENCIL_VIEW) == RenderTargetTextureFlags::RENDER_TARGET_TEXTURE_FLAGS_RENDER_TARGET_DEPTH_STENCIL_VIEW)
			{
				if (IsDepthStencilFormat(InTextureResourceCreateInformation.TextureInformation.ResourceFormat))
				{
					ViewMetaData MetaData;
					switch (InTextureResourceCreateInformation.TextureInformation.Dimension)
					{
					case ResourceDimension::RESOURCE_DIMENSION_TEXTURE_1D:
					case ResourceDimension::RESOURCE_DIMENSION_TEXTURE_2D:
					{
					} break;
					case ResourceDimension::RESOURCE_DIMENSION_TEXTURE_1D_ARRAY:
					{
						MetaData.DepthStencilViewTexture1DArray.ArraySize	= InTextureResourceCreateInformation.TextureInformation.DepthOrArraySize;
					} break;
					case ResourceDimension::RESOURCE_DIMENSION_TEXTURE_2D_ARRAY:
					case ResourceDimension::RESOURCE_DIMENSION_TEXTURE_3D:
					case ResourceDimension::RESOURCE_DIMENSION_TEXTURE_CUBE:
					case ResourceDimension::RESOURCE_DIMENSION_TEXTURE_CUBE_ARRAY:
					{
						MetaData.DepthStencilViewTexture2DArray.ArraySize	= InTextureResourceCreateInformation.TextureInformation.DepthOrArraySize;
					} break;
					}
					DepthStencilViewCreateInformation TextureDepthStencilViewCreateInformation(
						InContext,
						_Texture,
						MetaData,
						InTextureResourceCreateInformation.TextureInformation.ResourceFormat,
						ConvertResourceDimensionToViewDepthStencilType(InTextureResourceCreateInformation.TextureInformation.Dimension)
					);
					_RenderTargetDepthStencilView = CreateDepthStencilView(TextureDepthStencilViewCreateInformation);
				}
				else
				{
					ViewMetaData MetaData;
					switch (InTextureResourceCreateInformation.TextureInformation.Dimension)
					{
					case ResourceDimension::RESOURCE_DIMENSION_TEXTURE_1D:
					case ResourceDimension::RESOURCE_DIMENSION_TEXTURE_2D:
					{
					} break;
					case ResourceDimension::RESOURCE_DIMENSION_TEXTURE_1D_ARRAY:
					{
						MetaData.RenderTargetViewTexture1DArray.ArraySize	= InTextureResourceCreateInformation.TextureInformation.DepthOrArraySize;
					} break;
					case ResourceDimension::RESOURCE_DIMENSION_TEXTURE_2D_ARRAY:
					case ResourceDimension::RESOURCE_DIMENSION_TEXTURE_CUBE:
					case ResourceDimension::RESOURCE_DIMENSION_TEXTURE_CUBE_ARRAY:
					{
						MetaData.RenderTargetViewTexture2DArray.ArraySize	= InTextureResourceCreateInformation.TextureInformation.DepthOrArraySize;
					} break;
					case ResourceDimension::RESOURCE_DIMENSION_TEXTURE_3D:
					{
						MetaData.RenderTargetViewTexture3D.WSize			= InTextureResourceCreateInformation.TextureInformation.DepthOrArraySize;
					} break;
					}
					RenderTargetViewCreateInformation TextureRenderTargetViewCreateInformation(
						InContext,
						_Texture,
						MetaData,
						InTextureResourceCreateInformation.TextureInformation.ResourceFormat,
						ConvertResourceDimensionToViewRenderTargetType(InTextureResourceCreateInformation.TextureInformation.Dimension)
					);
					_RenderTargetDepthStencilView = CreateRenderTargetView(TextureRenderTargetViewCreateInformation);
				}
			}

			if ((Flags & RenderTargetTextureFlags::RENDER_TARGET_TEXTURE_FLAGS_UNORDERED_ACCESS_VIEW) == RenderTargetTextureFlags::RENDER_TARGET_TEXTURE_FLAGS_UNORDERED_ACCESS_VIEW)
			{
				ViewMetaData MetaData;
				switch (InTextureResourceCreateInformation.TextureInformation.Dimension)
				{
				case ResourceDimension::RESOURCE_DIMENSION_TEXTURE_1D:
				case ResourceDimension::RESOURCE_DIMENSION_TEXTURE_2D:
				{
				} break;
				case ResourceDimension::RESOURCE_DIMENSION_TEXTURE_1D_ARRAY:
				{
					MetaData.UnorderedAccessViewTexture1DArray.ArraySize	= InTextureResourceCreateInformation.TextureInformation.DepthOrArraySize;
				} break;
				case ResourceDimension::RESOURCE_DIMENSION_TEXTURE_2D_ARRAY:
				case ResourceDimension::RESOURCE_DIMENSION_TEXTURE_CUBE:
				case ResourceDimension::RESOURCE_DIMENSION_TEXTURE_CUBE_ARRAY:
				{
					MetaData.UnorderedAccessViewTexture2DArray.ArraySize	= InTextureResourceCreateInformation.TextureInformation.DepthOrArraySize;
				} break;
				case ResourceDimension::RESOURCE_DIMENSION_TEXTURE_3D:
				{
					MetaData.UnorderedAccessViewTexture3D.WSize				= InTextureResourceCreateInformation.TextureInformation.MIPLevels;
				} break;
				}
				UnorderedAccessViewCreateInformation TextureUnorderedAccessViewCreateInformation(
					InContext,
					_Texture,
					MetaData,
					ConvertDepthStencilFormatToFormat(InTextureResourceCreateInformation.TextureInformation.ResourceFormat),
					ConvertResourceDimensionToViewUnorderedAccessType(InTextureResourceCreateInformation.TextureInformation.Dimension)
				);
				_UnorderedAccessView = CreateUnorderedAccessView(TextureUnorderedAccessViewCreateInformation);
			}
		}

		RenderTargetTexture::~RenderTargetTexture()
		{
			delete _ShaderResourceView;
			_ShaderResourceView = nullptr;

			delete _RenderTargetDepthStencilView;
			_RenderTargetDepthStencilView = nullptr;

			delete _UnorderedAccessView;
			_UnorderedAccessView = nullptr;

			delete _Texture;
			_Texture = nullptr;
		}
	}
}
