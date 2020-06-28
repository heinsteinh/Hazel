#include "MouseButtonReleaseEvent.h"

#include "Hazel/Events/EventListener.h"

namespace Hazel
{
	void MouseButtonReleaseEvent::DispatchMouseButtonEvent(EventListener &listener)
	{
		listener.OnMouseButtonReleased(*this);
	}
}