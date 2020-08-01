#pragma once

#include "Hazel/Events/EventDispatcher.h"

namespace Hazel
{
	class EventHandler
	{
	private:
		EventDispatcher dispatcher;
		int repeatCount = 0;

	public:
		void SetEventListener(EventListener *listener);
		void OnResize(int width, int height);
		void OnClose();
		void OnKey(int key, int scancode, int action, int mods);
		void OnChar(uint32_t key);
		void OnMouseButton(int button, int action);
		void OnMouseScrolled(double x, double y);
		void OnMouseMoved(double x, double y);
	};
}