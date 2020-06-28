#include "WindowCloseEvent.h"

#include "Hazel/Events/EventListener.h"

namespace Hazel
{
	void WindowCloseEvent::DispatchApplicationEvent(EventListener &listener)
	{
		listener.OnWindowClosed(*this);
	}
}