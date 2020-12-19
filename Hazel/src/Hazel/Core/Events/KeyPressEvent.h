#pragma once

#include "KeyEvent.h"

namespace Hazel
{
	class KeyPressEvent : public KeyEvent
	{
	public:
		static constexpr EventType Type = EventType::KeyPress;

	private:
		int repeatCount = 0;

	public:
		constexpr KeyPressEvent(Key key, int scancode, KeyModifier keyModifiers, int repeatCount)
			: KeyEvent(Type, key, scancode, keyModifiers),
			repeatCount(repeatCount)
		{
		}

		constexpr int GetRepeatCount() const
		{
			return repeatCount;
		}

		constexpr bool IsRepeat() const
		{
			return repeatCount != 0;
		}

		virtual std::string ToString() const override
		{
			return (std::ostringstream()
				<< KeyEvent::ToString()
				<< " (" << repeatCount << " repeats)").str();
		}
	};
}