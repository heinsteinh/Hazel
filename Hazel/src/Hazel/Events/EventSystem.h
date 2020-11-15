#pragma once

#include "Hazel/Window/Window.h"
#include "Helpers/EventReceiver.h"

namespace Hazel
{
	class EventSystem
	{
	public:
		using Callback = EventReceiver::Callback;

	private:
		GLFWwindow *window = nullptr;
		EventReceiver receiver;

	public:
		EventSystem(const Window &window);
		~EventSystem();

		void PollEvents();

		inline void SendEvent(Event &e)
		{
			receiver.SendEvent(e);
		}

		inline void SetCallback(const Callback &callback)
		{
			receiver.SetCallback(callback);
		}
	};
}