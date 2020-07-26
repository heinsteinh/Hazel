#pragma once

#include "Hazel/Events/Event.h"

namespace Hazel
{
	class MouseScrollEvent : public Event
	{
	private:
		glm::vec2 offset{0.0f};

	public:
		constexpr MouseScrollEvent(float x, float y)
			: Event(EventType::MouseScroll, EventCategory::Input | EventCategory::Mouse),
			offset(x, y)
		{
		}

		constexpr const glm::vec2 &GetOffset() const
		{
			return offset;
		}

		inline virtual std::string ToString() const override
		{
			return (std::ostringstream() << GetName() << ": " << offset.x << ", " << offset.y).str();
		}
	};
}