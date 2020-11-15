#pragma once

#include "../WindowCloseEvent.h"
#include "../WindowResizeEvent.h"
#include "../KeyPressEvent.h"
#include "../KeyReleaseEvent.h"
#include "../KeyTypeEvent.h"
#include "../MouseButtonPressEvent.h"
#include "../MouseButtonReleaseEvent.h"
#include "../MouseMoveEvent.h"
#include "../MouseScrollEvent.h"

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

		inline void SendEvent(Event &e)
		{
			callback(e);
		}

		inline void SetCallback(const Callback &callback)
		{
			this->callback = callback;
		}
	};
}