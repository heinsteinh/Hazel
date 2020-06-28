#include "WindowResizeEvent.h"

#include "Hazel/Events/EventListener.h"

namespace Hazel
{
	std::string WindowResizeEvent::ToString() const
	{
		return (std::ostringstream()
			<< GetName() << ": " << width << ", " << height)
			.str();
	}

	void WindowResizeEvent::DispatchApplicationEvent(EventListener &listener)
	{
		listener.OnWindowResized(*this);
	}
}