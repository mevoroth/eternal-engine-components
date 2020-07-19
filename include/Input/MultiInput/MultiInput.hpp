#ifndef _MULTI_INPUT_HPP_
#define _MULTI_INPUT_HPP_

#include "Input/Input.hpp"

namespace Eternal
{
	namespace Input
	{
		using namespace std;

		class MultiInput : public Input
		{
		public:
			MultiInput();

			virtual void Update() override {}
			virtual void NotifyKeyPressed(_In_ const Key& KeyName) override;
			virtual void NotifyKeyReleased(_In_ const Key& KeyName) override;
			virtual void NotifyAxis(_In_ const Axis& AxisName, _In_ float AxisValue) override;
			virtual bool IsPressed(_In_ const Key& KeyName) override;
			virtual bool IsReleased(_In_ const Key& KeyName) override;
			virtual bool IsUp(_In_ const Key& KeyName) override;
			virtual bool IsDown(_In_ const Key& KeyName) override;
			virtual float GetAxis(_In_ const Axis& AxisName) override;

			void Add(_In_ Input* InputObj);

		private:
			vector<Input*> _Inputs;
		};
	}
}

#endif
