#pragma once

#include "Event.h"

namespace Hazel
{
	class MouseMoveEvent : public Event
	{
	public:
		static constexpr EventType Type = EventType::MouseMove;

	private:
		glm::vec2 position{0.0f};

	public:
		constexpr MouseMoveEvent(float x, float y)
			: Event(Type, EventCategory::Input | EventCategory::Mouse),
			position(x, y)
		{
		}

		constexpr const glm::vec2 &GetPosition() const
		{
			return position;
		}

		virtual std::string ToString() const override
		{
			return (std::ostringstream() << GetName() << ": " << position.x << ", " << position.y).str();
		}
	};
}