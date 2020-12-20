#include "EventSystem.h"

#include "GLFW/glfw3.h"

#include "Private/GlfwEventCallback.h"

namespace Hazel
{
	EventSystem::~EventSystem()
	{
		RemoveWindow();
	}

	void EventSystem::SetWindow(const Window &window)
	{
		RemoveWindow();
		this->window = window.GetHandle();
		GlfwEventCallback::SetupCallbacks(this->window, receiver);
	}

	void EventSystem::PollEvents()
	{
		glfwPollEvents();
	}

	void EventSystem::RemoveWindow()
	{
		if (window)
		{
			GlfwEventCallback::RemoveCallbacks(window);
			window = nullptr;
		}
	}
}