#pragma once

#include "Event.h"

namespace Hazel
{
	class WindowCloseEvent : public Event
	{
	public:
		static constexpr EventType Type = EventType::WindowClose;

		constexpr WindowCloseEvent()
			: Event(Type, EventCategory::Window)
		{
		}
	};
}