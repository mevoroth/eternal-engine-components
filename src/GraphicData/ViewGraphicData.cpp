#include "GraphicData/ViewGraphicData.hpp"

#include "Graphics/GraphicsInclude.hpp"
#include "Camera/Camera.hpp"
#include "ShadersReflection/HLSLPerViewConstants.hpp"

namespace Eternal
{
	namespace GraphicData
	{
		void UploadViewCameraToBuffer(_Inout_ HLSL::PerViewConstants* InOutViewConstants, _In_ Components::Camera* InCamera, _In_ float InViewWidth, _In_ float InViewHeight)
		{
			using namespace Eternal::Types;

			InCamera->GetWorldToClip(InOutViewConstants->WorldToClip);
			InCamera->GetClipToWorld(InOutViewConstants->ClipToWorld);
			InCamera->GetWorldToView(InOutViewConstants->WorldToView);
			InCamera->GetViewToWorld(InOutViewConstants->ViewToWorld);
			InCamera->GetViewToClip(InOutViewConstants->ViewToClip);
			InCamera->GetClipToView(InOutViewConstants->ClipToView);
			InOutViewConstants->ViewPosition			= Vector4(InCamera->GetPosition(), 1.0f);
			InOutViewConstants->ViewForward				= Vector4(InCamera->GetForward(), 0.0f);
			InOutViewConstants->ViewSizeAndInverseSize	= Vector4(
				InViewWidth,
				InViewHeight,
				1.0f / InViewWidth,
				1.0f / InViewHeight
			);
			InOutViewConstants->ViewRenderNearPlane		= InCamera->GetRenderNear();
			InOutViewConstants->ViewRenderFarPlane		= InCamera->GetRenderFar();
		}

		void UploadViewCameraToBuffer(_In_ Graphics::Resource& InResource, _In_ Components::Camera* InCamera, _In_ float InViewWidth, _In_ float InViewHeight)
		{
			using namespace Eternal::Graphics;
			using namespace Eternal::HLSL;

			MapRange ViewBufferRange(sizeof(PerViewConstants));
			MapScope<PerViewConstants> ViewBufferMapScope(InResource, ViewBufferRange);
			UploadViewCameraToBuffer(ViewBufferMapScope.GetDataPointer(), InCamera, InViewWidth, InViewHeight);
		}
	}
}
