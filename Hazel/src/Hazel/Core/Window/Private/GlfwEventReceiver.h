#pragma once

#include <functional>

namespace Hazel
{
	class Event;

	using EventCallback = std::function<void(Event &)>;

	class GlfwEventReceiver
	{
	private:
		EventCallback callback;
		int repeatCount = 0;

	public:
		void OnWindowResized(int width, int height);
		void OnWindowClosed();
		void OnKey(int key, int scancode, int action, int mods);
		void OnChar(unsigned int key);
		void OnMouseButton(int button, int action);
		void OnMouseScrolled(double x, double y);
		void OnMouseMoved(double x, double y);

		void SendEvent(Event &e)
		{
			callback(e);
		}

		void SetCallback(const EventCallback &callback)
		{
			this->callback = callback;
		}
	};
}