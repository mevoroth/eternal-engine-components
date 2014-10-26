#ifndef _WIN_INPUT_HPP_
#define _WIN_INPUT_HPP_

#include "Input/Input.hpp"
#define VC_EXTRALEAN
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <Xinput.h>

namespace Eternal
{
	namespace Input
	{
		class WinInput : public Input
		{
		private:
			// Xbox360 Pad
			DWORD _changed[XUSER_MAX_COUNT];

		public:
			WinInput();
			void Update();
		};
	}
}

#endif
