#ifndef _CAMERA_MATERIAL_PROPERTY_HPP_
#define _CAMERA_MATERIAL_PROPERTY_HPP_

#include "GraphicData/MaterialProperty.hpp"
#include "Types/Types.hpp"

namespace Eternal
{
	namespace Graphics
	{
		class Constant;
	}

	namespace Components
	{
		class Camera;
	}

	namespace GraphicData
	{
		using namespace Eternal::Components;
		using namespace Eternal::Graphics;
		using namespace Eternal::Types;

		class CameraMaterialProperty : public MaterialProperty
		{
		public:
			struct CommonConstants
			{
				Matrix4x4 ViewProjection;
			};

			virtual void Apply(_In_ Context& ContextObj) override;
			virtual void Reset(_In_ Context& ContextObj) override;
			void SetCamera(_In_ Camera* CameraObj);
			void SetConstant(_In_ Constant* ConstantObj);

		private:
			Constant* _Constant = nullptr;
			Camera* _Camera = nullptr;
		};
	}
}

#endif
