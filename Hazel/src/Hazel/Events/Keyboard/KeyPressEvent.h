#pragma once

#include "KeyEvent.h"

namespace Hazel
{
	class KeyPressEvent : public KeyEvent
	{
	private:
		int repeatCount = 0;

	public:
		constexpr KeyPressEvent(Key key, int scancode, KeyModifier keyModifiers, int repeatCount)
			: KeyEvent(EventType::KeyPress, key, scancode, keyModifiers),
			repeatCount(repeatCount)
		{
		}

		constexpr int GetRepeatCount() const
		{
			return repeatCount;
		}

		inline virtual std::string ToString() const override
		{
			return (std::ostringstream()
				<< KeyEvent::ToString()
				<< " (" << repeatCount << " repeats)").str();
		}
	};
}