#pragma once

#include "Application/WindowCloseEvent.h"
#include "Application/WindowResizeEvent.h"
#include "Keyboard/KeyPressEvent.h"
#include "Keyboard/KeyReleaseEvent.h"
#include "Keyboard/KeyTypeEvent.h"
#include "Mouse/MouseButtonPressEvent.h"
#include "Mouse/MouseButtonReleaseEvent.h"
#include "Mouse/MouseMoveEvent.h"
#include "Mouse/MouseScrollEvent.h"

namespace Hazel
{
	class EventListener
	{
	public:
		virtual ~EventListener() = default;

		inline virtual void OnEvent(Event &e)
		{
		}

		inline virtual void OnWindowResized(WindowResizeEvent &e)
		{
		}

		inline virtual void OnWindowClosed(WindowCloseEvent &e)
		{
		}

		inline virtual void OnKeyPressed(KeyPressEvent &e)
		{
		}

		inline virtual void OnKeyReleased(KeyReleaseEvent &e)
		{
		}

		inline virtual void OnKeyTyped(KeyTypeEvent &e)
		{
		}

		inline virtual void OnMouseMoved(MouseMoveEvent &e)
		{
		}

		inline virtual void OnMouseScrolled(MouseScrollEvent &e)
		{
		}

		inline virtual void OnMouseButtonPressed(MouseButtonPressEvent &e)
		{
		}

		inline virtual void OnMouseButtonReleased(MouseButtonReleaseEvent &e)
		{
		}
	};
}