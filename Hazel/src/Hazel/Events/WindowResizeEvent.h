#pragma once

#include "Event.h"
#include "Hazel/Geometry/Size.h"

namespace Hazel
{
	class WindowResizeEvent : public Event
	{
	public:
		static constexpr EventType Type = EventType::WindowResize;

	private:
		glm::vec2 size;

	public:
		constexpr WindowResizeEvent(float width, float height)
			: Event(Type, EventCategory::Window),
			size(width, height)
		{
		}

		constexpr const glm::vec2 &GetWindowSize() const
		{
			return size;
		}

		constexpr float GetWindowAspectRatio() const
		{
			return Size::GetAspectRatio(size);
		}

		constexpr bool IsWindowMinimized() const
		{
			return Size::IsEmpty(size);
		}

		virtual std::string ToString() const override
		{
			return (std::ostringstream() << GetName() << ": " << size.x << ", " << size.y).str();
		}
	};
}