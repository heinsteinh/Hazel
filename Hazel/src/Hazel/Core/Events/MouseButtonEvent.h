#pragma once

#include "Event.h"
#include "Hazel/Core/Input/MouseButtonName.h"

namespace Hazel
{
	class MouseButtonEvent : public Event
	{
	private:
		MouseButton button;

	public:
		constexpr MouseButtonEvent(EventType type, MouseButton button)
			: Event(type, EventCategory::Input | EventCategory::Mouse | EventCategory::MouseButton),
			button(button)
		{
		}

		constexpr MouseButton GetButton() const
		{
			return button;
		}

		virtual std::string ToString() const override
		{
			return (std::ostringstream() << GetName() << ": " << MouseButtonName::GetMouseButtonName(button)).str();
		}
	};
}