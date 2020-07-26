#pragma once

#include "Hazel/Events/Event.h"

namespace Hazel
{
	class MouseMoveEvent : public Event
	{
	private:
		glm::vec2 position{0.0f};

	public:
		constexpr MouseMoveEvent(float x, float y)
			: Event(EventType::MouseMove, EventCategory::Input | EventCategory::Mouse),
			position(x, y)
		{
		}

		constexpr const glm::vec2 &GetPosition() const
		{
			return position;
		}

		inline virtual std::string ToString() const override
		{
			return (std::ostringstream() << GetName() << ": " << position.x << ", " << position.y).str();
		}
	};
}