#include "Camera/PerspectiveCamera.hpp"

namespace Eternal
{
	namespace Components
	{
		PerspectiveCamera::PerspectiveCamera(_In_ float InNear, _In_ float InFar, _In_ float InYFOV, _In_ float InScreenRatio)
			: Camera(InNear, InFar)
			, _YFOV(InYFOV)
			, _ScreenRatio(InScreenRatio)
		{
		}

		void PerspectiveCamera::SetYFOV(_In_ float InYFOV)
		{
			_YFOV = InYFOV;
			_Dirty = true;
		}

		void PerspectiveCamera::SetScreenRatio(_In_ float Ratio)
		{
			_ScreenRatio = Ratio;
			_Dirty = true;
		}

		void PerspectiveCamera::_UpdateViewToClip()
		{
			_ViewToClip = ReverseZPerspectiveLHMatrix(_Near, _Far, _YFOV, _ScreenRatio);
			_ClipToView = ReverseZInversePerspectiveLHMatrix(_Near, _Far, _YFOV, _ScreenRatio);
		}
	}
}
