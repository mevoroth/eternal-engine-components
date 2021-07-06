#include "Input/Input.hpp"

using namespace Eternal::Input;

Input* Input::_Instance = nullptr;

Input::Input()
{
	//ETERNAL_ASSERT(!_Inst);

	_States = new uint8_t[KEY_COUNT];
	for (int i = 0; i < KEY_COUNT; ++i)
	{
		_States[i] = 0;
	}

	_Axis = new float[AXIS_COUNT];
	for (int i = 0; i < AXIS_COUNT; ++i)
	{
		_Axis[i] = 0.f;
	}

	//_Inst = this;
}

Input::~Input()
{
	delete[] _States;
	_States = nullptr;
	delete[] _Axis;
	_Axis = nullptr;
}

Input* Input::Get()
{
	ETERNAL_ASSERT(_Instance);
	return _Instance;
}

void Input::Initialize(_In_ Input* InInput)
{
	ETERNAL_ASSERT(!_Instance);
	ETERNAL_ASSERT(InInput);
	_Instance = InInput;
}

bool Eternal::Input::Input::IsDown(_In_ const Key& KeyName)
{
	return _States[KeyName] == INPUT_PREVIOUS_STATE;
}

bool Eternal::Input::Input::IsUp(_In_ const Key& KeyName)
{
	return _States[KeyName] == INPUT_CURRENT_STATE;
}

bool Eternal::Input::Input::IsPressed(_In_ const Key& KeyName)
{
	return (_States[KeyName] & INPUT_CURRENT_STATE) != 0;
}

bool Eternal::Input::Input::IsReleased(_In_ const Key& KeyName)
{
	return (_States[KeyName] & INPUT_CURRENT_STATE) != 0;
}

float Eternal::Input::Input::GetAxis(_In_ const Axis& AxisName)
{
	return _Axis[AxisName];
}
