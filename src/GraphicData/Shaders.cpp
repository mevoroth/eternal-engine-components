#include "GraphicData/Shaders.hpp"

#include "NextGenGraphics/ShaderFactory.hpp"
#include "Graphics/ShaderType.hpp"

using namespace Eternal::GraphicData;

Shaders::Shaders()
	: StaticCollection<ShaderKey, Shader, SHADER_COUNT>()
{
}

void Shaders::Initialize(_In_ Device& DeviceObj)
{
	GetArray()[POST_PROCESS_VS] = ShaderFactory::Get()->GetShader(DeviceObj, "PostProcessVS", "postprocess.vs.hlsl", ShaderType::VS);
	GetArray()[DEBUG_RENDER_PS] = ShaderFactory::Get()->GetShader(DeviceObj, "DebugRenderPS", "debugrender.ps.hlsl", ShaderType::PS);
	GetArray()[SHADER_OPAQUE_VS]	= ShaderFactory::Get()->GetShader(DeviceObj, "OpaqueVS", "opaque.vs.hlsl", ShaderType::VS);
	GetArray()[SHADER_OPAQUE_PS]	= ShaderFactory::Get()->GetShader(DeviceObj, "OpaquePS", "opaque.ps.hlsl", ShaderType::PS);
}
