#include "MouseButtonEvent.h"

#include "Hazel/Events/EventListener.h"

namespace Hazel
{
	std::string MouseButtonEvent::ToString() const
	{
		return (std::ostringstream()
			<< GetName() << ": " << static_cast<int>(button))
			.str();
	}

	void MouseButtonEvent::DispatchMouseEvent(EventListener &listener)
	{
		listener.OnMouseButtonEvent(*this);
		if (!IsHandled())
		{
			DispatchMouseButtonEvent(listener);
		}
	}
}