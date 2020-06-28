#include "MouseMoveEvent.h"

#include "Hazel/Events/EventListener.h"

namespace Hazel
{
	std::string MouseMoveEvent::ToString() const
	{
		return (std::ostringstream()
			<< GetName() << ": " << xPosition << ", " << yPosition)
			.str();
	}

	void MouseMoveEvent::DispatchMouseEvent(EventListener &listener)
	{
		listener.OnMouseMoved(*this);
	}
}