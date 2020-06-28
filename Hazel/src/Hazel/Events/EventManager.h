#pragma once

#include "Helpers/EventHandler.h"

struct GLFWwindow;

namespace Hazel
{
	class EventManager
	{
	private:
		EventHandler eventHandler;

		static EventHandler &GetHandler(GLFWwindow *window);

	public:
		EventManager(GLFWwindow *window);

		void PollEvents();
		void SetEventListener(EventListener *listener);

	private:
		void SetupCallbacks(GLFWwindow *window);
		void SetupWindowCallbacks(GLFWwindow *window);
		void SetupKeyCallbacks(GLFWwindow *window);
		void SetupMouseCallbacks(GLFWwindow *window);
	};
}