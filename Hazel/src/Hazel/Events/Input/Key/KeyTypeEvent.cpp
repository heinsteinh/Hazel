#include "KeyTypeEvent.h"

#include "Hazel/Events/EventListener.h"

namespace Hazel
{
	std::string KeyTypeEvent::ToString() const
	{
		return (std::ostringstream()
			<< GetName() << ": " << key)
			.str();
	}

	void KeyTypeEvent::DispatchKeyEvent(EventListener &listener)
	{
		listener.OnKeyTyped(*this);
	}
}