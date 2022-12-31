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

	namespace GraphicData
	{
		void UploadViewCameraToBuffer(_In_ Graphics::Resource& InResource, _In_ Components::Camera* InCamera, _In_ float ViewWidth, _In_ float ViewHeight);
	}
}
