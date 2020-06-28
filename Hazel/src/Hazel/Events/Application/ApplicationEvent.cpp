#include "ApplicationEvent.h"

#include "Hazel/Events/EventListener.h"

namespace Hazel
{
	void ApplicationEvent::DispatchEvent(EventListener &listener)
	{
		listener.OnApplicationEvent(*this);
		if (!IsHandled())
		{
			DispatchApplicationEvent(listener);
		}
	}
}