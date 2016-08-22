#ifndef _INPUT_FACTORY_HPP_
#define _INPUT_FACTORY_HPP_

namespace Eternal
{
	namespace Input
	{
		class Input;

		enum InputType
		{
			WIN,
			XINPUT,
			MULTI
		};

		Input* CreateInput(_In_ const InputType& InputTypeObj);
		Input* CreateMultiInput(_In_ Input** Inputs, _In_ int InputsCount);
	}
}

#endif
