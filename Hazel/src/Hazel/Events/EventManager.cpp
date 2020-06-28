#include "EventManager.h"

#include "GLFW/glfw3.h"

namespace Hazel
{
	EventHandler &EventManager::GetHandler(GLFWwindow *window)
	{
		return *static_cast<EventHandler *>(glfwGetWindowUserPointer(window));
	}

	EventManager::EventManager(const Window &window)
	{
		glfwSetWindowUserPointer(window.GetHandle(), &eventHandler);
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

	void EventManager::SetupCallbacks(const Window &window)
	{
		Log::Debug("Window callbacks setup.");
		SetupWindowCallbacks(window);
		SetupKeyCallbacks(window);
		SetupMouseCallbacks(window);
		Log::Debug("Window callbacks setup OK.");
	}

	void EventManager::SetupWindowCallbacks(const Window &window)
	{
		glfwSetWindowSizeCallback(window.GetHandle(), [](GLFWwindow *window, int width, int height)
		{
			GetHandler(window).OnResize(width, height);
		});
		glfwSetWindowCloseCallback(window.GetHandle(), [](GLFWwindow *window)
		{
			GetHandler(window).OnClose();
		});
	}

	void EventManager::SetupKeyCallbacks(const Window &window)
	{
		glfwSetKeyCallback(window.GetHandle(), [](GLFWwindow *window, int key, int scancode, int action, int mods)
		{
			GetHandler(window).OnKey(key, action);
		});
		glfwSetCharCallback(window.GetHandle(), [](GLFWwindow *window, unsigned int key)
		{
			GetHandler(window).OnChar(key);
		});
	}

	void EventManager::SetupMouseCallbacks(const Window &window)
	{
		glfwSetMouseButtonCallback(window.GetHandle(), [](GLFWwindow *window, int button, int action, int mods)
		{
			GetHandler(window).OnMouseButton(button, action);
		});
		glfwSetScrollCallback(window.GetHandle(), [](GLFWwindow *window, double x, double y)
		{
			GetHandler(window).OnMouseScrolled(x, y);
		});
		glfwSetCursorPosCallback(window.GetHandle(), [](GLFWwindow *window, double x, double y)
		{
			GetHandler(window).OnMouseMoved(x, y);
		});
	}
}