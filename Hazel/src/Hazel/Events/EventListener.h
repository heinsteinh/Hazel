#pragma once

#include "Application/WindowCloseEvent.h"
#include "Application/WindowResizeEvent.h"
#include "Input/Key/KeyPressEvent.h"
#include "Input/Key/KeyReleaseEvent.h"
#include "Input/Key/KeyTypeEvent.h"
#include "Input/Mouse/MouseButtonPressEvent.h"
#include "Input/Mouse/MouseButtonReleaseEvent.h"
#include "Input/Mouse/MouseMoveEvent.h"
#include "Input/Mouse/MouseScrollEvent.h"

namespace Hazel
{
	class EventListener
	{
	public:
		virtual ~EventListener() = default;

		inline virtual void OnEvent(Event &e)
		{
		}

		inline virtual void OnApplicationEvent(ApplicationEvent &e)
		{
		}

		inline virtual void OnWindowResized(WindowResizeEvent &e)
		{
		}

		inline virtual void OnWindowClosed(WindowCloseEvent &e)
		{
		}

		inline virtual void OnInputEvent(InputEvent &e)
		{
		}

		inline virtual void OnKeyEvent(KeyEvent &e)
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

		inline virtual void OnMouseEvent(MouseEvent &e)
		{
		}

		inline virtual void OnMouseMoved(MouseMoveEvent &e)
		{
		}

		inline virtual void OnMouseScrolled(MouseScrollEvent &e)
		{
		}

		inline virtual void OnMouseButtonEvent(MouseButtonEvent &e)
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