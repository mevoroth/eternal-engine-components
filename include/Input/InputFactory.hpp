#ifndef _INPUT_FACTORY_HPP_
#define _INPUT_FACTORY_HPP_

#include <vector>

namespace Eternal
{
	namespace Input
	{
		class Input;

		enum class InputType
		{
			WIN,
			XINPUT,
			MULTI
		};

		Input* CreateInput(_In_ const InputType& InInputType);
		Input* CreateMultiInput(_In_ const std::vector<InputType>& InInputTypes);
	}
}

#endif
