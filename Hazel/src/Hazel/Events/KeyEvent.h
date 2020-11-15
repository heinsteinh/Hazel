#pragma once

#include "Event.h"
#include "Hazel/Input/KeyName.h"
#include "Hazel/Input/KeyModifierName.h"

namespace Hazel
{
	class KeyEvent : public Event
	{
	private:
		Key key = Key::Invalid;
		int scancode = 0;
		KeyModifier modifiers = KeyModifier::None;

	public:
		constexpr KeyEvent(EventType type, Key key, int scancode, KeyModifier modifiers)
			: Event(type, EventCategory::Input | EventCategory::Keyboard),
			key(key),
			scancode(scancode),
			modifiers(modifiers)
		{
		}

		constexpr Key GetKey() const
		{
			return key;
		}

		constexpr int GetScancode() const
		{
			return scancode;
		}

		constexpr KeyModifier GetModifiers() const
		{
			return modifiers;
		}

		constexpr bool HasModifier(KeyModifier modifier) const
		{
			return modifiers & modifier;
		}

		inline virtual std::string ToString() const override
		{
			return (std::ostringstream()
				<< GetName() << ": "
				<< KeyName::GetKeyName(key) << ", "
				<< KeyName::GetScancodeName(scancode) << " (" << scancode << "), "
				<< KeyModifierName::GetKeyModifierName(modifiers)).str();
		}
	};
}