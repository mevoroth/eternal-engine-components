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
			XINPUT
		};

		Input* CreateInput(const InputType& InputTypeObj);
	}
}

#endif
