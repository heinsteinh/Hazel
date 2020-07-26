#include "EventHandler.h"

#include "GLFW/glfw3.h"

#include "Hazel/Input/Helpers/GlfwKeyMap.h"

namespace Hazel
{
	void EventHandler::SetEventListener(EventListener *listener)
	{
		dispatcher.SetListener(listener);
	}

	void EventHandler::OnResize(int width, int height)
	{
		dispatcher.Dispatch(WindowResizeEvent(static_cast<float>(width), static_cast<float>(height)));
	}

	void EventHandler::OnClose()
	{
		dispatcher.Dispatch(WindowCloseEvent());
	}

	void EventHandler::OnKey(int key, int scancode, int action, int mods)
	{
		switch (action)
		{
		case GLFW_PRESS:
			dispatcher.Dispatch(KeyPressEvent(
				GlfwKeyMap::GetHazelKey(key),
				scancode,
				static_cast<KeyModifier>(mods),
				0));
			repeatCount = 0;
			break;
		case GLFW_RELEASE:
			dispatcher.Dispatch(KeyReleaseEvent(
				GlfwKeyMap::GetHazelKey(key),
				scancode,
				static_cast<KeyModifier>(mods)));
			repeatCount = 0;
			break;
		case GLFW_REPEAT:
			repeatCount++;
			dispatcher.Dispatch(KeyPressEvent(
				GlfwKeyMap::GetHazelKey(key),
				scancode,
				static_cast<KeyModifier>(mods),
				repeatCount));
		}
	}

	void EventHandler::OnChar(unsigned int key)
	{
		dispatcher.Dispatch(KeyTypeEvent(key));
	}

	void EventHandler::OnMouseButton(int button, int action)
	{
		switch (action)
		{
		case GLFW_PRESS:
			dispatcher.Dispatch(MouseButtonPressEvent(static_cast<MouseButton>(button)));
			break;
		case GLFW_RELEASE:
			dispatcher.Dispatch(MouseButtonReleaseEvent(static_cast<MouseButton>(button)));
		}
	}

	void EventHandler::OnMouseScrolled(double x, double y)
	{
		dispatcher.Dispatch(MouseScrollEvent(static_cast<float>(x), static_cast<float>(y)));
	}

	void EventHandler::OnMouseMoved(double x, double y)
	{
		dispatcher.Dispatch(MouseMoveEvent(static_cast<float>(x), static_cast<float>(y)));
	}
}