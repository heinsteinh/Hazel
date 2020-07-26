#pragma once

#include "Hazel/Events/Event.h"

namespace Hazel
{
	class WindowCloseEvent : public Event
	{
	public:
		constexpr WindowCloseEvent()
			: Event(EventType::WindowClose, EventCategory::Window)
		{
		}
	};
}