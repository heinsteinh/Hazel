#include "MouseButtonPressEvent.h"

#include "Hazel/Events/EventListener.h"

namespace Hazel
{
	void MouseButtonPressEvent::DispatchMouseButtonEvent(EventListener &listener)
	{
		listener.OnMouseButtonPressed(*this);
	}
}