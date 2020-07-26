#pragma once

#include "Hazel/Events/Event.h"
#include "Hazel/Input/MouseButtonName.h"

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

		inline virtual std::string ToString() const override
		{
			return (std::ostringstream() << GetName() << ": " << MouseButtonName::GetMouseButtonName(button)).str();
		}
	};
}