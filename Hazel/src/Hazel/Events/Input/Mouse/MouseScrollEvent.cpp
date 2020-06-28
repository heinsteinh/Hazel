#include "MouseScrollEvent.h"

#include "Hazel/Events/EventListener.h"

namespace Hazel
{
	std::string MouseScrollEvent::ToString() const
	{
		return (std::ostringstream()
			<< GetName() << ": " << xOffset << ", " << yOffset)
			.str();
	}

	void MouseScrollEvent::DispatchMouseEvent(EventListener &listener)
	{
		listener.OnMouseScrolled(*this);
	}
}