#include "Input/Input.hpp"

#include "Macros/Macros.hpp"

#include <cassert>

using namespace Eternal::Input;

Input* Input::_Inst = 0;

Input::Input()
{
	//ETERNAL_ASSERT(!_Inst);

	_States = new uint8_t[KEYS_COUNT];
	for (int i = 0; i < KEYS_COUNT; ++i)
	{
		_States[i] = 0;
	}

	_Axis = new float[AXIS_COUNT];
	for (int i = 0; i < AXIS_COUNT; ++i)
	{
		_Axis[i] = 0.f;
	}

	_Inst = this;
}

Input::~Input()
{
	delete[] _States;
	delete[] _Axis;
}

Input* Input::Get()
{
	ETERNAL_ASSERT(_Inst);
	return _Inst;
}

bool Input::IsDown(const Key& key)
{
	return _States[key] == INPUT_PREVIOUS_STATE;
}

bool Input::IsUp(const Key& key)
{
	return _States[key] == INPUT_CURRENT_STATE;
}

bool Input::IsPressed(const Key& key)
{
	return (_States[key] & INPUT_CURRENT_STATE) != 0;
}

bool Input::IsReleased(const Key& key)
{
	return (_States[key] & INPUT_CURRENT_STATE) != 0;
}

float Input::GetAxis(const Axis& axis)
{
	return _Axis[axis];
}
