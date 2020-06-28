#pragma once

#include "Hazel/Window/Window.h"
#include "Helpers/EventHandler.h"

namespace Hazel
{
	class EventManager
	{
	private:
		EventHandler eventHandler;

		static EventHandler &GetHandler(GLFWwindow *window);

	public:
		EventManager(const Window &window);

		void PollEvents();
		void SetEventListener(EventListener *listener);

	private:
		void SetupCallbacks(const Window &window);
		void SetupWindowCallbacks(const Window &window);
		void SetupKeyCallbacks(const Window &window);
		void SetupMouseCallbacks(const Window &window);
	};
}