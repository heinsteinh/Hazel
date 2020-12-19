#pragma once

#include "Hazel/Core/Events/WindowCloseEvent.h"
#include "Hazel/Core/Events/WindowResizeEvent.h"
#include "Hazel/Core/Events/KeyPressEvent.h"
#include "Hazel/Core/Events/KeyReleaseEvent.h"
#include "Hazel/Core/Events/KeyTypeEvent.h"
#include "Hazel/Core/Events/MouseButtonPressEvent.h"
#include "Hazel/Core/Events/MouseButtonReleaseEvent.h"
#include "Hazel/Core/Events/MouseMoveEvent.h"
#include "Hazel/Core/Events/MouseScrollEvent.h"

namespace Hazel
{
	class EventReceiver
	{
	public:
		using Callback = std::function<void(Event &)>;

	private:
		Callback callback;
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

		void SetCallback(const Callback &callback)
		{
			this->callback = callback;
		}
	};
}