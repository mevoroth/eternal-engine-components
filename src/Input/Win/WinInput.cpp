#include "Input/Win/WinInput.hpp"
#include <string>
using namespace Eternal::Input;

WinInput::WinInput()
	: Input()
{
	for (DWORD i = 0; i < XUSER_MAX_COUNT; ++i)
	{
		_changed[i] = -1;
	}
}

void WinInput::Update()
{
	_Pad();
}

void WinInput::_Pad()
{
	// Update Pad
	for (DWORD i = 0; i < XUSER_MAX_COUNT; ++i)
	{
		XINPUT_STATE state;
		ZeroMemory(&state, sizeof(XINPUT_STATE));
		if (XInputGetState(i, &state) == ERROR_SUCCESS)
		{
			for (int j = JOY0_UP + i * 24, c = i + 24; j < c; ++j)
			{
				_states[j] = _states[j] << 1;
			}
			if (state.dwPacketNumber != _changed[i])
			{
				int pad = i * 6;
				_axis[JOY0_LX + pad] = (float)state.Gamepad.sThumbLX / 32767.f;
				_axis[JOY0_LY + pad] = (float)state.Gamepad.sThumbLY / 32767.f;
				_axis[JOY0_RX + pad] = (float)state.Gamepad.sThumbRX / 32767.f;
				_axis[JOY0_RY + pad] = (float)state.Gamepad.sThumbRY / 32767.f;
				_axis[JOY0_ZM + pad] = (float)state.Gamepad.bLeftTrigger / 255.f;
				_axis[JOY0_ZP + pad] = (float)state.Gamepad.bRightTrigger / 255.f;

				pad = i * 24; // 20 buttons + D-Pad (4 buttons)
				_states[JOY0_UP + pad] |= (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP) ? 0x1 : 0x0;
				_states[JOY0_DOWN + pad] |= (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP) ? 0x1 : 0x0;
				_states[JOY0_LEFT + pad] |= (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP) ? 0x1 : 0x0;
				_states[JOY0_RIGHT + pad] |= (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP) ? 0x1 : 0x0;
				_states[JOY0_BUTTON0 + pad] |= (state.Gamepad.wButtons & XINPUT_GAMEPAD_A) ? 0x1 : 0x0;
				_states[JOY0_BUTTON1 + pad] |= (state.Gamepad.wButtons & XINPUT_GAMEPAD_B) ? 0x1 : 0x0;
				_states[JOY0_BUTTON2 + pad] |= (state.Gamepad.wButtons & XINPUT_GAMEPAD_X) ? 0x1 : 0x0;
				_states[JOY0_BUTTON3 + pad] |= (state.Gamepad.wButtons & XINPUT_GAMEPAD_Y) ? 0x1 : 0x0;
				_states[JOY0_BUTTON4 + pad] |= (state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER) ? 0x1 : 0x0;
				_states[JOY0_BUTTON5 + pad] |= (state.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER) ? 0x1 : 0x0;
				_states[JOY0_BUTTON6 + pad] |= (state.Gamepad.wButtons & XINPUT_GAMEPAD_BACK) ? 0x1 : 0x0;
				_states[JOY0_BUTTON7 + pad] |= (state.Gamepad.wButtons & XINPUT_GAMEPAD_START) ? 0x1 : 0x0;
				_states[JOY0_BUTTON8 + pad] |= (state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_THUMB) ? 0x1 : 0x0;
				_states[JOY0_BUTTON9 + pad] |= (state.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_THUMB) ? 0x1 : 0x0;

				_changed[i] = state.dwPacketNumber;
			}
			else
			{
				for (int j = JOY0_UP + i * 24, c = i + 24; j < c; ++j)
				{
#ifdef ETERNAL_DEBUG
					assert(!(_states[i] & 0x1));
#endif
					_states[j] |= (_states[j] & 0x2) >> 1; // _states[i] |= (_states[i] & (0x1 << 1)) >> 1;
				}
			}
		}
		else
		{
			if (_changed[i] != -1)
			{
				for (int j = JOY0_UP + i * 24, c = i + 24; j < c; ++j)
				{
					_states[j] = 0;
				}
				_changed[i] != -1;
			}
		}
	}
}
