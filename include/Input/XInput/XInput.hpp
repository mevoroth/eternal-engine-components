#ifndef _X_INPUT_HPP_
#define _X_INPUT_HPP_

#include "Input/Input.hpp"
#define VC_EXTRALEAN
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <Xinput.h>

namespace Eternal
{
	namespace Input
	{
		class XInput : public Input
		{
		private:
			// Xbox360 Pad
			DWORD _Changed[XUSER_MAX_COUNT];

		public:
			XInput();
			virtual void Update() override;
			virtual void NotifyKeyPressed(const Key& KeyName) override {}
			virtual void NotifyKeyReleased(const Key& KeyName) override {}

		private:
			void _Pad();
		};
	}
}

#endif
