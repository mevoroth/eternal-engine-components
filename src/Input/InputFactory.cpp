#include "Input/InputFactory.hpp"

#include "Macros/Macros.hpp"
#include "Input/WinInput/WinInput.hpp"
#include "Input/XInput/XInput.hpp"
#include "Input/MultiInput/MultiInput.hpp"

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

			case MULTI:	// Must be created with CreateMultiInput
			default:
				ETERNAL_ASSERT(false);
				break;
			}
			return nullptr;
		}

		Input* CreateMultiInput(_In_ Input** Inputs, _In_ int InputsCount)
		{
			MultiInput* MultiInputObj = new MultiInput();
			for (int InputIndex = 0; InputIndex < InputsCount; ++InputIndex)
				MultiInputObj->Add(Inputs[InputIndex]);
			return MultiInputObj;
		}
	}
}
