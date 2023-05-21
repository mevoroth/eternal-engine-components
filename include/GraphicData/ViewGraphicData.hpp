#pragma once

namespace Eternal
{
	namespace Graphics
	{
		class Resource;
	}

	namespace Components
	{
		class Camera;
	}

	namespace HLSL
	{
		struct PerViewConstants;
	}

	namespace GraphicData
	{
		void UploadViewCameraToBuffer(_Inout_ HLSL::PerViewConstants* InOutViewConstants, _In_ Components::Camera* InCamera, _In_ float InViewWidth, _In_ float InViewHeight);
		void UploadViewCameraToBuffer(_In_ Graphics::Resource& InResource, _In_ Components::Camera* InCamera, _In_ float InViewWidth, _In_ float InViewHeight);
	}
}
