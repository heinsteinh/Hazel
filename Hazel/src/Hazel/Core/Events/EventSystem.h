#pragma once

#include "Hazel/Core/Window/Window.h"
#include "Private/EventReceiver.h"

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
		~EventSystem();

		void SetWindow(const Window &window);
		void PollEvents();
		void RemoveWindow();

		void SendEvent(Event &e)
		{
			receiver.SendEvent(e);
		}

		void SetCallback(const Callback &callback)
		{
			receiver.SetCallback(callback);
		}
	};
}