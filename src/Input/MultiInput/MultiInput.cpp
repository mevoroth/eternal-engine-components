#include "Input/MultiInput/MultiInput.hpp"

#include "Macros/Macros.hpp"
#include <cmath>

using namespace Eternal::Input;

MultiInput::MultiInput()
	: Input()
{
	Initialize(this);
}

void MultiInput::NotifyKeyPressed(_In_ const Key& KeyName)
{
	for (int InputIndex = 0; InputIndex < _Inputs.size(); ++InputIndex)
		_Inputs[InputIndex]->NotifyKeyPressed(KeyName);
}
void MultiInput::NotifyKeyReleased(_In_ const Key& KeyName)
{
	for (int InputIndex = 0; InputIndex < _Inputs.size(); ++InputIndex)
		_Inputs[InputIndex]->NotifyKeyReleased(KeyName);
}
void MultiInput::NotifyAxis(_In_ const Axis& AxisName, _In_ float AxisValue)
{
	for (int InputIndex = 0; InputIndex < _Inputs.size(); ++InputIndex)
		_Inputs[InputIndex]->NotifyAxis(AxisName, AxisValue);
}
bool MultiInput::IsPressed(_In_ const Key& KeyName)
{
	bool Pressed = false;
	for (int InputIndex = 0; !Pressed && InputIndex < _Inputs.size(); ++InputIndex)
		Pressed = _Inputs[InputIndex]->IsPressed(KeyName);
	return Pressed;
}
bool MultiInput::IsReleased(_In_ const Key& KeyName)
{
	bool Released = false;
	for (int InputIndex = 0; !Released && InputIndex < _Inputs.size(); ++InputIndex)
		Released = _Inputs[InputIndex]->IsReleased(KeyName);
	return Released;
}
bool MultiInput::IsUp(_In_ const Key& KeyName)
{
	bool Up = false;
	for (int InputIndex = 0; !Up && InputIndex < _Inputs.size(); ++InputIndex)
		Up = _Inputs[InputIndex]->IsUp(KeyName);
	return Up;
}
bool MultiInput::IsDown(_In_ const Key& KeyName)
{
	bool Down = false;
	for (int InputIndex = 0; !Down && InputIndex < _Inputs.size(); ++InputIndex)
		Down = _Inputs[InputIndex]->IsDown(KeyName);
	return Down;
}
float MultiInput::GetAxis(_In_ const Axis& AxisName)
{
	float AxisValue = 0.f;
	for (int InputIndex = 0; InputIndex < _Inputs.size(); ++InputIndex)
	{
		float CurrentAxisValue = _Inputs[InputIndex]->GetAxis(AxisName);
		if (CurrentAxisValue != 0.f)
		{
			ETERNAL_ASSERT(AxisValue == 0.f);
			AxisValue = CurrentAxisValue;
		}
	}
	return AxisValue;
}

void MultiInput::Add(_In_ Input* InputObj)
{
	ETERNAL_ASSERT(InputObj);
	_Inputs.push_back(InputObj);
}
