#pragma once

#include "Hazel/Events/Categories/Categories.h"

namespace Hazel
{
    class HAZEL_API EventListener
    {
    public:
        virtual ~EventListener() = default;

        virtual void OnEvent(Event &e)
        {
        }

        virtual void OnApplicationEvent(ApplicationEvent &e)
        {
        }

        virtual void OnWindowClosed(WindowClosedEvent &e)
        {
        }

        virtual void OnWindowResized(WindowResizedEvent &e)
        {
        }

        virtual void OnInputEvent(InputEvent &e)
        {
        }

        virtual void OnKeyEvent(KeyEvent &e)
        {
        }

        virtual void OnKeyPressed(KeyPressedEvent &e)
        {
        }

        virtual void OnKeyReleased(KeyReleasedEvent &e)
        {
        }

        virtual void OnKeyTyped(KeyTypedEvent &e)
        {
        }

        virtual void OnMouseEvent(MouseEvent &e)
        {
        }

        virtual void OnMouseMoved(MouseMovedEvent &e)
        {
        }

        virtual void OnMouseScrolled(MouseScrolledEvent &e)
        {
        }

        virtual void OnMouseButtonEvent(MouseButtonEvent &e)
        {
        }

        virtual void OnMouseButtonPressed(MouseButtonPressedEvent &e)
        {
        }

        virtual void OnMouseButtonReleased(MouseButtonReleasedEvent &e)
        {
        }
    };
}