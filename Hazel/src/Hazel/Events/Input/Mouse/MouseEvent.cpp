#include "MouseEvent.h"

#include "Hazel/Events/EventListener.h"

namespace Hazel
{
	void MouseEvent::DispatchInputEvent(EventListener &listener)
	{
		listener.OnMouseEvent(*this);
		if (!IsHandled())
		{
			DispatchMouseEvent(listener);
		}
	}
}