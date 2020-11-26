#pragma once

#include "Event.h"

namespace Hazel
{
	class MouseScrollEvent : public Event
	{
	public:
		static constexpr EventType Type = EventType::MouseScroll;

	private:
		glm::vec2 offset{0.0f};

	public:
		constexpr MouseScrollEvent(float x, float y)
			: Event(Type, EventCategory::Input | EventCategory::Mouse),
			offset(x, y)
		{
		}

		constexpr const glm::vec2 &GetOffset() const
		{
			return offset;
		}

		virtual std::string ToString() const override
		{
			return (std::ostringstream() << GetName() << ": " << offset.x << ", " << offset.y).str();
		}
	};
}