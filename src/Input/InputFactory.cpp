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

		Input* CreateInput(const InputType& InputTypeObj)
		{
			switch (InputTypeObj)
			{
			case WIN:
				Eternal::Log::Log::Get()->Write(Eternal::Log::Log::Info, Eternal::Log::Log::Engine, "[Input::CreateInput]Creating Windows Keyboard input");
				return new WinInput();

			case XINPUT:
				Eternal::Log::Log::Get()->Write(Eternal::Log::Log::Info, Eternal::Log::Log::Engine, "[Input::CreateInput]Creating Xbox Pad input");
				return new XInput();

			case MULTI:	// Must be created with CreateMultiInput
			default:
				ETERNAL_ASSERT(false);
				break;
			}
			return nullptr;
		}

		Input* CreateMultiInput(_In_ Input** Inputs, _In_ uint32_t InputsCount)
		{
			Eternal::Log::Log::Get()->Write(Eternal::Log::Log::Info, Eternal::Log::Log::Engine, "[Input::CreateMultiInput]Creating Multi input");
			MultiInput* MultiInputObj = new MultiInput();
			for (uint32_t InputIndex = 0; InputIndex < InputsCount; ++InputIndex)
				MultiInputObj->Add(Inputs[InputIndex]);
			return MultiInputObj;
		}
	}
}
