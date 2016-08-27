#ifndef _MATERIAL_HPP_
#define _MATERIAL_HPP_

#include <vector>
#include <string>
#include "GraphicData/MaterialProperty.hpp"

namespace Eternal
{
	namespace Graphics
	{
		class Context;
	}

	namespace GraphicData
	{
		using namespace std;

		class Material : public MaterialProperty
		{
		public:
			void SetMaterialName(_In_ const string& MaterialName);
			string& GetMaterialName();
			void SetProperties(_In_ vector<MaterialProperty*>* Properties);
			virtual void Apply(_In_ Context& ContextObj) override;
			virtual void Reset(_In_ Context& ContextObj) override;

		private:
			vector<MaterialProperty*>* _Properties = nullptr;
#ifdef ETERNAL_DEBUG
			string _MaterialName;
#endif
		};
	}
}

#endif
