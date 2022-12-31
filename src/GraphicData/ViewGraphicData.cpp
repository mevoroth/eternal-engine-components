#include "GraphicData/ViewGraphicData.hpp"

#include "Graphics/GraphicsInclude.hpp"
#include "Camera/Camera.hpp"
#include "HLSLPerViewConstants.hpp"

namespace Eternal
{
	namespace GraphicData
	{
		void UploadViewCameraToBuffer(_In_ Graphics::Resource& InResource, _In_ Components::Camera* InCamera, _In_ float ViewWidth, _In_ float ViewHeight)
		{
			using namespace Eternal::Graphics;
			using namespace Eternal::Types;
			using namespace Eternal::HLSL;

			MapRange ViewBufferRange(sizeof(PerViewConstants));
			MapScope<PerViewConstants> ViewBufferMapScope(InResource, ViewBufferRange);
			PerViewConstants* ViewConstantsPointer = ViewBufferMapScope.GetDataPointer();

			InCamera->GetWorldToClip(ViewConstantsPointer->WorldToClip);
			InCamera->GetClipToWorld(ViewConstantsPointer->ClipToWorld);
			InCamera->GetWorldToView(ViewConstantsPointer->WorldToView);
			InCamera->GetViewToWorld(ViewConstantsPointer->ViewToWorld);
			InCamera->GetViewToClip(ViewConstantsPointer->ViewToClip);
			InCamera->GetClipToView(ViewConstantsPointer->ClipToView);
			ViewConstantsPointer->ViewPosition				= Vector4(InCamera->GetPosition(), 1.0f);
			ViewConstantsPointer->ViewForward				= Vector4(InCamera->GetForward(), 0.0f);
			ViewConstantsPointer->ViewSizeAndInverseSize	= Vector4(
				ViewWidth,
				ViewHeight,
				1.0f / ViewWidth,
				1.0f / ViewHeight
			);
			ViewConstantsPointer->ViewRenderNearPlane		= InCamera->GetRenderNear();
			ViewConstantsPointer->ViewRenderFarPlane		= InCamera->GetRenderFar();
		}
	}
}
