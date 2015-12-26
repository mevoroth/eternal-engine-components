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
			virtual void NotifyKeyPressed(const Key& KeyName) override;
			virtual void NotifyKeyReleased(const Key& KeyName) override;

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
