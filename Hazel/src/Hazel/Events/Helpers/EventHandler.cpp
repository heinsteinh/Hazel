#include "EventHandler.h"

#include "GLFW/glfw3.h"

#include "Hazel/Input/GlfwKeyMap.h"

namespace Hazel
{
	void EventHandler::SetEventListener(EventListener *listener)
	{
		this->listener = listener;
	}

	void EventHandler::OnResize(int width, int height)
	{
		WindowResizeEvent(static_cast<float>(width), static_cast<float>(height)).Dispatch(listener);
	}

	void EventHandler::OnClose()
	{
		WindowCloseEvent().Dispatch(listener);
	}

	void EventHandler::OnKey(int key, int action)
	{
		switch (action)
		{
		case GLFW_PRESS:
			KeyPressEvent(GlfwKeyMap::GetHazelKey(key), 0).Dispatch(listener);
			repeatCount = 0;
			break;
		case GLFW_RELEASE:
			KeyReleaseEvent(GlfwKeyMap::GetHazelKey(key)).Dispatch(listener);
			repeatCount = 0;
			break;
		case GLFW_REPEAT:
			repeatCount++;
			KeyPressEvent(GlfwKeyMap::GetHazelKey(key), repeatCount).Dispatch(listener);
		}
	}

	void EventHandler::OnChar(int key)
	{
		KeyTypeEvent(key).Dispatch(listener);
	}

	void EventHandler::OnMouseButton(int button, int action)
	{
		switch (action)
		{
		case GLFW_PRESS:
			MouseButtonPressEvent(static_cast<MouseButton>(button)).Dispatch(listener);
			break;
		case GLFW_RELEASE:
			MouseButtonReleaseEvent(static_cast<MouseButton>(button)).Dispatch(listener);
		}
	}

	void EventHandler::OnMouseScrolled(double x, double y)
	{
		MouseScrollEvent(static_cast<float>(x), static_cast<float>(y)).Dispatch(listener);
	}

	void EventHandler::OnMouseMoved(double x, double y)
	{
		MouseMoveEvent(static_cast<float>(x), static_cast<float>(y)).Dispatch(listener);
	}
}