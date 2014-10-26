#include "Input/Input.hpp"

#include <cassert>

using namespace Eternal::Input;

Input* Input::_inst = 0;

Input::Input()
{
	assert(!_inst);

	_states = new uint8_t[KEYS_COUNT];
	for (int i = 0; i < KEYS_COUNT; ++i)
	{
		_states[i] = 0;
	}

	_axis = new float[AXIS_COUNT];
	for (int i = 0; i < AXIS_COUNT; ++i)
	{
		_axis[i] = 0.f;
	}

	_inst = this;
}

Input::~Input()
{
	delete[] _states;
	delete[] _axis;
}

Input* Input::Get()
{
	assert(_inst);
	return _inst;
}

bool Input::IsDown(const Key& key)
{
	return _states[key] == PREV;
}

bool Input::IsUp(const Key& key)
{
	return _states[key] == CUR;
}

bool Input::IsPressed(const Key& key)
{
	return (_states[key] & CUR);
}

bool Input::IsReleased(const Key& key)
{
	return (_states[key] & CUR);
}

float Input::GetAxis(const Axis& axis)
{
	return _axis[axis];
}
