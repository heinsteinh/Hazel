#include "EventManager.h"

#include "GLFW/glfw3.h"

namespace Hazel
{
	EventHandler &EventManager::GetHandler(GLFWwindow *window)
	{
		return *static_cast<EventHandler *>(glfwGetWindowUserPointer(window));
	}

	EventManager::EventManager(GLFWwindow *window)
	{
		glfwSetWindowUserPointer(window, &eventHandler);
		SetupCallbacks(window);
	}

	void EventManager::PollEvents()
	{
		glfwPollEvents();
	}

	void EventManager::SetEventListener(EventListener *listener)
	{
		eventHandler.SetEventListener(listener);
	}

	void EventManager::SetupCallbacks(GLFWwindow *window)
	{
		Log::Debug("Window callbacks setup.");
		SetupWindowCallbacks(window);
		SetupKeyCallbacks(window);
		SetupMouseCallbacks(window);
		Log::Debug("Window callbacks setup OK.");
	}

	void EventManager::SetupWindowCallbacks(GLFWwindow *window)
	{
		glfwSetWindowSizeCallback(window, [](GLFWwindow *window, int width, int height)
		{
			GetHandler(window).OnResize(width, height);
		});
		glfwSetWindowCloseCallback(window, [](GLFWwindow *window)
		{
			GetHandler(window).OnClose();
		});
	}

	void EventManager::SetupKeyCallbacks(GLFWwindow *window)
	{
		glfwSetKeyCallback(window, [](GLFWwindow *window, int key, int scancode, int action, int mods)
		{
			GetHandler(window).OnKey(key, action);
		});
		glfwSetCharCallback(window, [](GLFWwindow *window, unsigned int key)
		{
			GetHandler(window).OnChar(key);
		});
	}

	void EventManager::SetupMouseCallbacks(GLFWwindow *window)
	{
		glfwSetMouseButtonCallback(window, [](GLFWwindow *window, int button, int action, int mods)
		{
			GetHandler(window).OnMouseButton(button, action);
		});
		glfwSetScrollCallback(window, [](GLFWwindow *window, double x, double y)
		{
			GetHandler(window).OnMouseScrolled(x, y);
		});
		glfwSetCursorPosCallback(window, [](GLFWwindow *window, double x, double y)
		{
			GetHandler(window).OnMouseMoved(x, y);
		});
	}
}