#include "EventReceiver.h"

#include "GLFW/glfw3.h"

namespace Hazel
{
	void EventReceiver::OnWindowResized(int width, int height)
	{
		callback(WindowResizeEvent(static_cast<float>(width), static_cast<float>(height)));
	}

	void EventReceiver::OnWindowClosed()
	{
		callback(WindowCloseEvent());
	}

	void EventReceiver::OnKey(int key, int scancode, int action, int mods)
	{
		switch (action)
		{
		case GLFW_RELEASE:
			repeatCount = 0;
			callback(KeyReleaseEvent(static_cast<Key>(key), scancode, static_cast<KeyModifier>(mods)));
			break;
		case GLFW_PRESS:
			repeatCount = 0;
			callback(KeyPressEvent(static_cast<Key>(key), scancode, static_cast<KeyModifier>(mods), 0));
			break;
		case GLFW_REPEAT:
			repeatCount++;
			callback(KeyPressEvent(static_cast<Key>(key), scancode, static_cast<KeyModifier>(mods), repeatCount));
		}
	}

	void EventReceiver::OnChar(unsigned int key)
	{
		callback(KeyTypeEvent(key));
	}

	void EventReceiver::OnMouseButton(int button, int action)
	{
		switch (action)
		{
		case GLFW_RELEASE:
			callback(MouseButtonReleaseEvent(static_cast<MouseButton>(button)));
			break;
		case GLFW_PRESS:
			callback(MouseButtonPressEvent(static_cast<MouseButton>(button)));
		}
	}

	void EventReceiver::OnMouseScrolled(double x, double y)
	{
		callback(MouseScrollEvent(static_cast<float>(x), static_cast<float>(y)));
	}

	void EventReceiver::OnMouseMoved(double x, double y)
	{
		callback(MouseMoveEvent(static_cast<float>(x), static_cast<float>(y)));
	}
}