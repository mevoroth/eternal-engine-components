#include "GraphicData/Material.hpp"

//#include "GraphicData/MaterialProperty.hpp"

using namespace Eternal::GraphicData;

//void Material::SetProperties(_In_ vector<MaterialProperty*>* Properties)
//{
//	_Properties = Properties;
//}

//void Material::Apply(_In_ Context& ContextObj)
//{
//	for (int PropertyIndex = 0; PropertyIndex < _Properties->size(); ++PropertyIndex)
//	{
//		(*_Properties)[PropertyIndex]->Apply(ContextObj);
//	}
//}
//
//void Material::Reset(_In_ Context& ContextObj)
//{
//	for (int PropertyIndex = 0; PropertyIndex < _Properties->size(); ++PropertyIndex)
//	{
//		(*_Properties)[PropertyIndex]->Reset(ContextObj);
//	}
//}

void Material::SetMaterialName(_In_ const string& MaterialName)
{
#ifdef ETERNAL_DEBUG
	_MaterialName = MaterialName;
#endif
}

string& Material::GetMaterialName()
{
	static string DefaultMaterialName;
#ifdef ETERNAL_DEBUG
	return _MaterialName;
#else
	return DefaultMaterialName;
#endif
}
