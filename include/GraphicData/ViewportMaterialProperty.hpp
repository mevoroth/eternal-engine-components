#ifndef _VIEWPORT_MATERIAL_PROPERTY_HPP_
#define _VIEWPORT_MATERIAL_PROPERTY_HPP_

#include "GraphicData/MaterialProperty.hpp"

namespace Eternal
{
	namespace Graphics
	{
		class Viewport;
	}

	namespace GraphicData
	{
		class ViewportMaterialProperty : public MaterialProperty
		{
		public:
			virtual void Apply(_In_ Context& ContextObj) override;
			virtual void Reset(_In_ Context& ContextObj) override;

			void SetViewport(_In_ Viewport* ViewportObj);

		private:
			Viewport* _Viewport = nullptr;
		};
	}
}

#endif
