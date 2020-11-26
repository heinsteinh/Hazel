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
		Size size;

	public:
		constexpr WindowResizeEvent(float width, float height)
			: Event(Type, EventCategory::Window),
			size{width, height}
		{
		}

		constexpr Size GetSize() const
		{
			return size;
		}

		virtual std::string ToString() const override
		{
			return (std::ostringstream() << GetName() << ": " << size.Width << ", " << size.Height).str();
		}
	};
}