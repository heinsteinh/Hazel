#pragma once

#include "MouseButtonEvent.h"

namespace Hazel
{
	class MouseButtonPressEvent : public MouseButtonEvent
	{
	public:
		static constexpr EventType Type = EventType::MouseButtonPress;

		constexpr MouseButtonPressEvent(MouseButton button)
			: MouseButtonEvent(Type, button)
		{
		}
	};
}