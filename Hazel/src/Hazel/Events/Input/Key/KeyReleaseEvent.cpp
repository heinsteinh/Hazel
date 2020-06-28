#include "KeyReleaseEvent.h"

#include "Hazel/Events/EventListener.h"

namespace Hazel
{
	void KeyReleaseEvent::DispatchKeyEvent(EventListener &listener)
	{
		listener.OnKeyReleased(*this);
	}
}