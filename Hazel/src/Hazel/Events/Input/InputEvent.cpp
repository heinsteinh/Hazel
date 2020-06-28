#include "InputEvent.h"

#include "Hazel/Events/EventListener.h"

namespace Hazel
{
	void InputEvent::DispatchEvent(EventListener &listener)
	{
		listener.OnInputEvent(*this);
		if (!IsHandled())
		{
			DispatchInputEvent(listener);
		}
	}
}