#pragma once

#include "Hazel/Core/Events/EventType.h"

namespace Hazel
{
	class GuiEventFilter
	{
	public:
		static constexpr bool CanBlockEvent(EventType eventType)
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
	};
}