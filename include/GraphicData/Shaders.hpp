#ifndef _SHADERS_HPP_
#define _SHADERS_HPP_

#include "GraphicData/StaticCollection.hpp"

namespace Eternal
{
	namespace Graphics
	{
		class Shader;
	}

	namespace GraphicData
	{
		using namespace Eternal::Graphics;

		enum ShaderKey
		{
			POST_PROCESS_VS		= 0,
			DEBUG_RENDER_PS,
			SHADER_OPAQUE_VS,
			SHADER_OPAQUE_PS,
			SHADER_COUNT
		};

		class Shaders : public StaticCollection<ShaderKey, Shader, SHADER_COUNT>
		{
		public:
			Shaders();

			virtual void Initialize(_In_ Device& DeviceObj) override;
		};
	}
}

#endif
