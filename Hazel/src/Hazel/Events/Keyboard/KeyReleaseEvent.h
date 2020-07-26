#pragma once

#include "KeyEvent.h"

namespace Hazel
{
	class KeyReleaseEvent : public KeyEvent
	{
	public:
		constexpr KeyReleaseEvent(Key key, int scancode, KeyModifier keyModifiers)
			: KeyEvent(EventType::KeyRelease, key, scancode, keyModifiers)
		{
		}
	};
}