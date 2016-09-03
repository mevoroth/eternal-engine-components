#include "GraphicData/CameraMaterialProperty.hpp"

#include "Macros/Macros.hpp"
#include "Types/Types.hpp"
#include "Graphics/Context.hpp"
#include "Graphics/Constant.hpp"
#include "Graphics/Resource.hpp"
#include "Camera/Camera.hpp"

using namespace Eternal::GraphicData;

void CameraMaterialProperty::Apply(_In_ Context& ContextObj)
{
	ETERNAL_ASSERT(_Camera);
	ETERNAL_ASSERT(_Constant);
	
	Resource* ConstantResource = _Constant->GetAsResource();
	Resource::LockedResource CameraConstant = ConstantResource->Lock(ContextObj, Resource::LOCK_WRITE_DISCARD);
	_Camera->GetViewProjectionMatrix(((CommonConstants*)CameraConstant.Data)->ViewProjection);
	ConstantResource->Unlock(ContextObj);

	ContextObj.BindConstant<Context::VERTEX>(0, _Constant);
}

void CameraMaterialProperty::Reset(_In_ Context& ContextObj)
{
	ContextObj.UnbindConstant<Context::VERTEX>(0);
}

void CameraMaterialProperty::SetCamera(_In_ Camera* CameraObj)
{
	ETERNAL_ASSERT(CameraObj);
	_Camera = CameraObj;
}

void CameraMaterialProperty::SetConstant(_In_ Constant* ConstantObj)
{
	ETERNAL_ASSERT(ConstantObj);
	_Constant = ConstantObj;
}
