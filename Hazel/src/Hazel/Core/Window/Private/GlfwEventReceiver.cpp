#include "GlfwEventReceiver.h"

#include "GLFW/glfw3.h"

namespace Hazel
{
	void GlfwEventReceiver::OnWindowResize(int width, int height)
	{
		event.Type = EventType::WindowResize;
		event.Categories = EventCategory::Window;
		event.Blocked = false;
		event.WindowSize = {static_cast<float>(width), static_cast<float>(height)};
		callback(event);
	}

	void GlfwEventReceiver::OnWindowRefresh()
	{
		event.Type = EventType::WindowRefresh;
		event.Categories = EventCategory::Window;
		event.Blocked = false;
		callback(event);
	}

	void GlfwEventReceiver::OnWindowClose()
	{
		event.Type = EventType::WindowClose;
		event.Categories = EventCategory::Window;
		event.Blocked = false;
		callback(event);
	}

	void GlfwEventReceiver::OnKey(int key, int scancode, int action, int mods)
	{
		switch (action)
		{
		case GLFW_RELEASE:
			event.Type = EventType::KeyRelease;
			event.RepeatCount = 0;
			break;
		case GLFW_PRESS:
			event.Type = EventType::KeyPress;
			event.RepeatCount = 0;
			break;
		case GLFW_REPEAT:
			event.Type = EventType::KeyPress;
			event.RepeatCount++;
			break;
		default:
			return;
		}
		event.Categories = EventCategory::Input | EventCategory::Keyboard;
		event.Blocked = false;
		event.Key = static_cast<Key>(key);
		event.Scancode = scancode;
		event.KeyModifiers = static_cast<KeyModifier>(mods);
		callback(event);
	}

	void GlfwEventReceiver::OnChar(unsigned int key)
	{
		event.Type = EventType::KeyType;
		event.Categories = EventCategory::Input | EventCategory::Keyboard;
		event.Blocked = false;
		event.Text = key;
		callback(event);
	}

	void GlfwEventReceiver::OnMouseButton(int button, int action)
	{
		switch (action)
		{
		case GLFW_RELEASE:
			event.Type = EventType::MouseButtonRelease;
			break;
		case GLFW_PRESS:
			event.Type = EventType::MouseButtonPress;
			break;
		default:
			return;
		}
		event.Categories = EventCategory::Input | EventCategory::Mouse | EventCategory::MouseButton;
		event.Blocked = false;
		event.MouseButton = static_cast<MouseButton>(button);
		callback(event);
	}

	void GlfwEventReceiver::OnMouseScroll(double x, double y)
	{
		event.Type = EventType::MouseScroll;
		event.Categories = EventCategory::Input | EventCategory::Mouse;
		event.Blocked = false;
		event.MouseScrollOffset = {static_cast<float>(x), static_cast<float>(y)};
		callback(event);
	}

	void GlfwEventReceiver::OnMouseMove(double x, double y)
	{
		event.Type = EventType::MouseMove;
		event.Categories = EventCategory::Input | EventCategory::Mouse;
		event.Blocked = false;
		event.MousePosition = {static_cast<float>(x), static_cast<float>(y)};
		callback(event);
	}
}