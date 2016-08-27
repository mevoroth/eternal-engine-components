#ifndef _SHADER_MATERIAL_PROPERTY_HPP_
#define _SHADER_MATERIAL_PROPERTY_HPP_

#include "GraphicData/MaterialProperty.hpp"
#include "Graphics/Context.hpp"

namespace Eternal
{
	namespace GraphicData
	{
		using namespace Eternal::Graphics;

		template<Context::ShaderStage ShaderStageObj>
		class ShaderMaterialProperty : MaterialProperty
		{
		public:
			virtual void Apply(_In_ Context& ContextObj) override;
			virtual void Reset(_In_ Context& ContextObj) override;
			void SetShader(_In_ Shader* ShaderObj);

		private:
			Shader* _Shader;
		};

		template<Context::ShaderStage ShaderStageObj>
		void ShaderMaterialProperty<ShaderStageObj>::Apply(_In_ Context& ContextObj)
		{
			ContextObj.BindShader<ShaderStageObj>(_Shader);
		}

		template<Context::ShaderStage ShaderStageObj>
		void ShaderMaterialProperty<ShaderStageObj>::Reset(_In_ Context& ContextObj)
		{
			ContextObj.UnbindShader<ShaderStageObj>();
		}

		template<Context::ShaderStage ShaderStageObj>
		void ShaderMaterialProperty<ShaderStageObj>::SetShader(_In_ Shader* ShaderObj)
		{
			_Shader = ShaderObj;
		}
	}
}

#endif
