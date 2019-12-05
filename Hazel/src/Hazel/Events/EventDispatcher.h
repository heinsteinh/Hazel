#pragma once

#include "Hazel/Core/Core.h"
#include "Categories/Categories.h"
#include "EventListener.h"

namespace Hazel
{
    class HAZEL_API EventDispatcher
    {
    private:
        EventListener *listener;

    public:
        EventDispatcher(EventListener *listener = nullptr);

        void SetListener(EventListener *listener);
        void Dispatch(Event &e);

    private:
        inline bool DispatchEvent(Event &e)
        {
            return TryHandle(&EventListener::OnEvent, e);
        }

        inline bool DispatchApplicationEvent(Event &e)
        {
            return DispatchEvent(e)
                || TryHandle(&EventListener::OnApplicationEvent, e);
        }

        inline bool DispatchWindowClosedEvent(Event &e)
        {
            return DispatchApplicationEvent(e)
                || TryHandle(&EventListener::OnWindowClosed, e);
        }

        inline bool DispatchWindowResizedEvent(Event &e)
        {
            return DispatchApplicationEvent(e)
                || TryHandle(&EventListener::OnWindowResized, e);
        }

        inline bool DispatchInputEvent(Event &e)
        {
            return DispatchEvent(e)
                || TryHandle(&EventListener::OnInputEvent, e);
        }

        inline bool DispatchKeyEvent(Event &e)
        {
            return DispatchInputEvent(e)
                || TryHandle(&EventListener::OnKeyEvent, e);
        }

        inline bool DispatchKeyPressedEvent(Event &e)
        {
            return DispatchKeyEvent(e)
                || TryHandle(&EventListener::OnKeyPressed, e);
        }

        inline bool DispatchKeyReleasedEvent(Event &e)
        {
            return DispatchKeyEvent(e)
                || TryHandle(&EventListener::OnKeyReleased, e);
        }

        inline bool DispatchKeyTypedEvent(Event &e)
        {
            return DispatchKeyEvent(e)
                || TryHandle(&EventListener::OnKeyTyped, e);
        }

        inline bool DispatchMouseEvent(Event &e)
        {
            return DispatchInputEvent(e)
                || TryHandle(&EventListener::OnMouseEvent, e);
        }

        inline bool DispatchMouseMovedEvent(Event &e)
        {
            return DispatchMouseEvent(e)
                || TryHandle(&EventListener::OnMouseMoved, e);
        }

        inline bool DispatchMouseScrolledEvent(Event &e)
        {
            return DispatchMouseEvent(e)
                || TryHandle(&EventListener::OnMouseScrolled, e);
        }

        inline bool DispatchMouseButtonEvent(Event &e)
        {
            return DispatchMouseEvent(e)
                || TryHandle(&EventListener::OnMouseButtonEvent, e);
        }

        inline bool DispatchMouseButtonPressedEvent(Event &e)
        {
            return DispatchMouseButtonEvent(e)
                || TryHandle(&EventListener::OnMouseButtonPressed, e);
        }

        inline bool DispatchMouseButtonReleasedEvent(Event &e)
        {
            return DispatchMouseButtonEvent(e)
                || TryHandle(&EventListener::OnMouseButtonReleased, e);
        }

        template<typename T>
        inline bool TryHandle(void (EventListener:: *method)(T &), Event &e)
        {
            (listener->*method)((T &)e);
            return e.IsHandled();
        }
    };
}