#pragma once

namespace Hazel
{
    class Event;
    class WindowClosedEvent;
    class WindowResizedEvent;
    class KeyTypedEvent;
    class KeyPressedEvent;
    class KeyReleasedEvent;
    class MouseMovedEvent;
    class MouseScrolledEvent;
    class MouseButtonPressedEvent;
    class MouseButtonReleasedEvent;

    class HAZEL_API EventListener
    {
    public:
        virtual ~EventListener() = default;

        virtual void OnEvent(Event &e)
        {
        }

        virtual void OnWindowClosed(WindowClosedEvent &e)
        {
        }

        virtual void OnWindowResized(WindowResizedEvent &e)
        {
        }

        virtual void OnKeyTyped(KeyTypedEvent &e)
        {
        }

        virtual void OnKeyPressed(KeyPressedEvent &e)
        {
        }

        virtual void OnKeyReleased(KeyReleasedEvent &e)
        {
        }

        virtual void OnMouseMoved(MouseMovedEvent &e)
        {
        }

        virtual void OnMouseScrolled(MouseScrolledEvent &e)
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