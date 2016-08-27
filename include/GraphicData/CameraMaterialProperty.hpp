#ifndef _CAMERA_MATERIAL_PROPERTY_HPP_
#define _CAMERA_MATERIAL_PROPERTY_HPP_

#include "GraphicData/MaterialProperty.hpp"

namespace Eternal
{
	namespace Components
	{
		class Camera;
	}

	namespace GraphicData
	{
		using namespace Eternal::Components;

		class CameraMaterialProperty : public MaterialProperty
		{
		public:
			virtual void Apply(_In_ Context& ContextObj) override;
			virtual void Reset(_In_ Context& ContextObj) override;
			void SetCamera(_In_ Camera* CameraObj);

		private:
			Camera* _Camera = nullptr;
		};
	}
}

#endif
