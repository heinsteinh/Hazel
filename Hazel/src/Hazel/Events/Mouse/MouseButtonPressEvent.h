#pragma once

#include "MouseButtonEvent.h"

namespace Hazel
{
	class MouseButtonPressEvent : public MouseButtonEvent
	{
	public:
		constexpr MouseButtonPressEvent(MouseButton button)
			: MouseButtonEvent(EventType::KeyPress, button)
		{
		}
	};
}