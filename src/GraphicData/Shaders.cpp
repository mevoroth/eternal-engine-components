#include "GraphicData/Shaders.hpp"

#include "NextGenGraphics/ShaderFactory.hpp"
#include "Graphics/ShaderType.hpp"

using namespace Eternal::GraphicData;

Shaders::Shaders()
	: StaticCollection<ShaderKey, Shader, SHADERS_COUNT>()
{
}

void Shaders::Initialize(_In_ Device& DeviceObj)
{
	GetArray()[SHADER_OPAQUE_VS] = ShaderFactory::Get()->GetShader(DeviceObj, "OpaqueVS", "opaque.vs.hlsl", VS);
	GetArray()[SHADER_OPAQUE_PS] = ShaderFactory::Get()->GetShader(DeviceObj, "OpaquePS", "opaque.ps.hlsl", PS);
}
