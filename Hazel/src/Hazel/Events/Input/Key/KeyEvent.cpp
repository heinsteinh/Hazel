#include "KeyEvent.h"

#include "Hazel/Events/EventListener.h"

namespace Hazel
{
	void KeyEvent::DispatchInputEvent(EventListener &listener)
	{
		listener.OnKeyEvent(*this);
		if (!IsHandled())
		{
			DispatchKeyEvent(listener);
		}
	}
}