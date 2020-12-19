#pragma once

#include "KeyEvent.h"

namespace Hazel
{
	class KeyReleaseEvent : public KeyEvent
	{
	public:
		static constexpr EventType Type = EventType::KeyRelease;

		constexpr KeyReleaseEvent(Key key, int scancode, KeyModifier keyModifiers)
			: KeyEvent(Type, key, scancode, keyModifiers)
		{
		}
	};
}