#pragma once

#include "imgui.h"

#include "Hazel/Events/Event.h"

namespace Hazel
{
	class GuiEventFilter
	{
	public:
		static constexpr bool CanBlockEventType(EventType eventType)
		{
			switch (eventType)
			{
			case EventType::KeyPress:
			case EventType::KeyType:
			case EventType::MouseButtonPress:
			case EventType::MouseScroll:
				return true;
			}
			return false;
		}

		static constexpr bool CanBlockEvent(Event &e)
		{
			return CanBlockEventType(e.GetType());
		}
	};
}