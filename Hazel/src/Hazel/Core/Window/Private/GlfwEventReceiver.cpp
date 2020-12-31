#include "GlfwEventReceiver.h"

#include "GLFW/glfw3.h"

#include "Hazel/Core/Events/WindowCloseEvent.h"
#include "Hazel/Core/Events/WindowResizeEvent.h"
#include "Hazel/Core/Events/KeyPressEvent.h"
#include "Hazel/Core/Events/KeyReleaseEvent.h"
#include "Hazel/Core/Events/KeyTypeEvent.h"
#include "Hazel/Core/Events/MouseButtonPressEvent.h"
#include "Hazel/Core/Events/MouseButtonReleaseEvent.h"
#include "Hazel/Core/Events/MouseMoveEvent.h"
#include "Hazel/Core/Events/MouseScrollEvent.h"

namespace Hazel
{
	void GlfwEventReceiver::OnWindowResized(int width, int height)
	{
		callback(WindowResizeEvent(static_cast<float>(width), static_cast<float>(height)));
	}

	void GlfwEventReceiver::OnWindowClosed()
	{
		callback(WindowCloseEvent());
	}

	void GlfwEventReceiver::OnKey(int key, int scancode, int action, int mods)
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

	void GlfwEventReceiver::OnChar(unsigned int key)
	{
		callback(KeyTypeEvent(key));
	}

	void GlfwEventReceiver::OnMouseButton(int button, int action)
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

	void GlfwEventReceiver::OnMouseScrolled(double x, double y)
	{
		callback(MouseScrollEvent(static_cast<float>(x), static_cast<float>(y)));
	}

	void GlfwEventReceiver::OnMouseMoved(double x, double y)
	{
		callback(MouseMoveEvent(static_cast<float>(x), static_cast<float>(y)));
	}
}