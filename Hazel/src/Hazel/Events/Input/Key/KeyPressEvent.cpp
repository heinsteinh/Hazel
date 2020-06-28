#include "KeyPressEvent.h"

#include "Hazel/Events/EventListener.h"

namespace Hazel
{
	std::string KeyPressEvent::ToString() const
	{
		return (std::ostringstream()
			<< GetName() << ": " << static_cast<int>(GetKey())
			<< " (" << repeatCount << " repeats)")
			.str();
	}

	void KeyPressEvent::DispatchKeyEvent(EventListener &listener)
	{
		listener.OnKeyPressed(*this);
	}
}