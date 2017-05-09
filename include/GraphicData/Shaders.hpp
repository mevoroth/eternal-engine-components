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
			SHADER_OPAQUE_VS	= 0,
			SHADER_OPAQUE_PS,
			SHADERS_COUNT
		};

		class Shaders : public StaticCollection<ShaderKey, Shader, SHADERS_COUNT>
		{
		public:
			Shaders();

			virtual void Initialize(_In_ Device& DeviceObj) override;
		};
	}
}

#endif
