#pragma once

#include <functional>

#include "Hazel/Core/Events/Event.h"

namespace Hazel
{
	using EventCallback = std::function<void(Event &)>;

	class GlfwEventReceiver
	{
	private:
		Event event;
		EventCallback callback;

	public:
		void OnWindowResize(int width, int height);
		void OnWindowRefresh();
		void OnWindowClose();
		void OnKey(int key, int scancode, int action, int mods);
		void OnChar(unsigned int key);
		void OnMouseButton(int button, int action);
		void OnMouseScroll(double x, double y);
		void OnMouseMove(double x, double y);

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