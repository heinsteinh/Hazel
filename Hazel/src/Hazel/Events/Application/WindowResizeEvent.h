#pragma once

#include "Hazel/Events/Event.h"
#include "Hazel/Geometry/Size.h"

namespace Hazel
{
	class WindowResizeEvent : public Event
	{
	private:
		Size size;

	public:
		constexpr WindowResizeEvent(float width, float height)
			: Event(EventType::WindowResize, EventCategory::Window),
			size{width, height}
		{
		}

		constexpr Size GetSize() const
		{
			return size;
		}

		inline virtual std::string ToString() const override
		{
			return (std::ostringstream() << GetName() << ": " << size.Width << ", " << size.Height).str();
		}
	};
}