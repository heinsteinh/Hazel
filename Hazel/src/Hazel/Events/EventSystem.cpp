#include "EventSystem.h"

#include "Helpers/GlfwEventCallback.h"

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