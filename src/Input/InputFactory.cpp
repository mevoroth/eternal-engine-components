#include "Input/InputFactory.hpp"

#include "Macros/Macros.hpp"
#include "Input/WinInput/WinInput.hpp"
#include "Input/XInput/XInput.hpp"

namespace Eternal
{
	namespace Input
	{
		Input* CreateInput(const InputType& InputTypeObj)
		{
			switch (InputTypeObj)
			{
			case WIN:
				return new WinInput();
				break;

			case XINPUT:
				return new XInput();
				break;

			default:
				ETERNAL_ASSERT(false);
				break;
			}
		}
	}
}
