#ifndef _WIN_INPUT_HPP_
#define _WIN_INPUT_HPP_

#include <vector>

#include "Input/Input.hpp"

namespace Eternal
{
	namespace Input
	{
		class WinInput : public Input
		{
		public:
			enum KeyState
			{
				DOWN = 0,
				UP = 1
			};

			WinInput();
			virtual void Update() override;
			virtual void NotifyKeyPressed(_In_ const Key& KeyName) override;
			virtual void NotifyKeyReleased(_In_ const Key& KeyName) override;
			virtual void NotifyAxis(_In_ const Axis& AxisName, _In_ float AxisValue) override;

		private:
			struct KeyRecord
			{
				KeyState State;
				Key KeyName;
				KeyRecord(const Key& KeyName, const KeyState& State)
					: KeyName(KeyName)
					, State(State)
				{
				}
			};

			std::vector<KeyRecord> _KeyRecords;
		};
	}
}

#endif
