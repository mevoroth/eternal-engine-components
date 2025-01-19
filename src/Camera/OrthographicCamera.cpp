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

		void OrthographicCamera::SetWidth(_In_ float InWidth)
		{
			_Width = InWidth;
			_Dirty = true;
		}

		void OrthographicCamera::SetHeight(_In_ float InHeight)
		{
			_Height = InHeight;
			_Dirty = true;
		}

		void OrthographicCamera::_UpdateViewToClip()
		{
#if ETERNAL_USE_REVERSED_Z
			_ViewToClip = ReverseZOrthographicLHMatrix(_Near, _Far, _Width, _Height);
			_ClipToView = ReverseZInverseOrthographicLHMatrix(_Near, _Far, _Width, _Height);
#else
			_ViewToClip = OrthographicLHMatrix(_Near, _Far, _Width, _Height);
			_ClipToView = InverseOrthographicLHMatrix(_Near, _Far, _Width, _Height);
#endif
		}
	}
}
