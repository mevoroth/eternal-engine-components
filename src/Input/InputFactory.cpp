#include "Input/InputFactory.hpp"

#include "Log/Log.hpp"
#include "Input/WinInput/WinInput.hpp"
#include "Input/XInput/XInput.hpp"
#include "Input/MultiInput/MultiInput.hpp"

namespace Eternal
{
	namespace Input
	{
		using namespace Eternal::Log;

		Input* CreateInput(const InputType& InInputType)
		{
			switch (InInputType)
			{
			case InputType::WIN:
				LogWrite(LogInfo, LogEngine, "[Input::CreateInput]Creating Windows Keyboard input");
				return new WinInput();

			case InputType::XINPUT:
				LogWrite(LogInfo, LogEngine, "[Input::CreateInput]Creating Xbox Pad input");
				return new XInput();

			case InputType::MULTI:	// Must be created with CreateMultiInput
			default:
				ETERNAL_BREAK();
				break;
			}
			return nullptr;
		}

		Input* CreateMultiInput(_In_ const std::vector<InputType>& InInputTypes)
		{
			LogWrite(LogInfo, LogEngine, "[Input::CreateMultiInput]Creating Multi input");
			MultiInput* OutMultiInput = new MultiInput();
			for (uint32_t InputIndex = 0; InputIndex < InInputTypes.size(); ++InputIndex)
				OutMultiInput->Add(CreateInput(InInputTypes[InputIndex]));
			return OutMultiInput;
		}
	}
}
