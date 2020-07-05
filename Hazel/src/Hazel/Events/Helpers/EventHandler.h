#pragma once

#include "Hazel/Events/EventListener.h"

namespace Hazel
{
	class EventHandler
	{
	private:
		EventListener *listener = nullptr;
		int repeatCount = 0;

	public:
		void SetEventListener(EventListener *listener);
		void OnResize(int width, int height);
		void OnClose();
		void OnKey(int key, int action);
		void OnChar(unsigned int key);
		void OnMouseButton(int button, int action);
		void OnMouseScrolled(double x, double y);
		void OnMouseMoved(double x, double y);
	};
}