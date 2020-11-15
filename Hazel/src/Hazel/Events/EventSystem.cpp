#include "EventSystem.h"

#include "Helpers/GlfwEventCallback.h"

namespace Hazel
{
	EventSystem::EventSystem(const Window &window)
		: window(window.GetHandle())
	{
		GlfwEventCallback::SetupCallbacks(this->window, receiver);
	}

	EventSystem::~EventSystem()
	{
		GlfwEventCallback::RemoveCallbacks(window);
	}

	void EventSystem::PollEvents()
	{
		glfwPollEvents();
	}
}