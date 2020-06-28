#include "WindowResizeEvent.h"

#include "Hazel/Events/EventListener.h"

namespace Hazel
{
	std::string WindowResizeEvent::ToString() const
	{
		return (std::ostringstream()
			<< GetName() << ": " << size.Width << ", " << size.Height)
			.str();
	}

	void WindowResizeEvent::DispatchApplicationEvent(EventListener &listener)
	{
		listener.OnWindowResized(*this);
	}
}