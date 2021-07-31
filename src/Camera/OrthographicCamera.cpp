#include "Camera/OrthographicCamera.hpp"

namespace Eternal
{
	namespace Components
	{
		OrthographicCamera::OrthographicCamera(_In_ float InNear, _In_ float InFar, _In_ float InWidth, _In_ float InHeight)
			: Camera(InNear, InFar)
			, _Width(InWidth)
			, _Height(InHeight)
		{
		}

		void OrthographicCamera::SetSize(_In_ float InSize)
		{
			_Width = InSize;
			_Dirty = true;
		}

		void OrthographicCamera::_UpdateViewToClip()
		{
			_ViewToClip = ReverseZOrthographicLHMatrix(_Near, _Far, _Width, _Height);
			_ClipToView = ReverseZInverseOrthographicLHMatrix(_Near, _Far, _Width, _Height);
		}
	}
}
