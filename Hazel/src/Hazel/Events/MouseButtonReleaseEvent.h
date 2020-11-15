#pragma once

#include "MouseButtonEvent.h"

namespace Hazel
{
	class MouseButtonReleaseEvent : public MouseButtonEvent
	{
	public:
		static constexpr EventType Type = EventType::MouseButtonRelease;

		constexpr MouseButtonReleaseEvent(MouseButton button)
			: MouseButtonEvent(Type, button)
		{
		}
	};
}