#pragma once

#include "EventListener.h"

namespace Hazel
{
	class EventDispatcher
	{
	private:
		EventListener *listener = nullptr;

	public:
		constexpr EventDispatcher(EventListener *listener = nullptr)
			: listener(listener)
		{
		}

		constexpr void SetListener(EventListener *listener)
		{
			this->listener = listener;
		}

		constexpr void Dispatch(Event &e)
		{
			if (!listener || e.IsHandled())
			{
				return;
			}
			listener->OnEvent(e);
			if (!e.IsHandled())
			{
				DispatchEvent(e);
			}
		}

	private:
		constexpr void DispatchEvent(Event &e)
		{
			switch (e.GetType())
			{
			case EventType::WindowClose:
				return listener->OnWindowClosed(static_cast<WindowCloseEvent &>(e));
			case EventType::WindowResize:
				return listener->OnWindowResized(static_cast<WindowResizeEvent &>(e));
			case EventType::KeyPress:
				return listener->OnKeyPressed(static_cast<KeyPressEvent &>(e));
			case EventType::KeyRelease:
				return listener->OnKeyReleased(static_cast<KeyReleaseEvent &>(e));
			case EventType::KeyType:
				return listener->OnKeyTyped(static_cast<KeyTypeEvent &>(e));
			case EventType::MouseButtonPress:
				return listener->OnMouseButtonPressed(static_cast<MouseButtonPressEvent &>(e));
			case EventType::MouseButtonRelease:
				return listener->OnMouseButtonReleased(static_cast<MouseButtonReleaseEvent &>(e));
			case EventType::MouseMove:
				return listener->OnMouseMoved(static_cast<MouseMoveEvent &>(e));
			case EventType::MouseScroll:
				return listener->OnMouseScrolled(static_cast<MouseScrollEvent &>(e));
			}
		}
	};
}