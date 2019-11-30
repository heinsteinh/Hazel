#pragma once

#include "Hazel/Core/Core.h"
#include "Categories/Categories.h"
#include "Listeners/Listeners.h"

namespace Hazel
{
    class HAZEL_API EventDispatcher
    {
    private:
        EventListener &listener;

    public:
        EventDispatcher(EventListener &listener)
            : listener(listener)
        {
        }

        void Dispatch(Event &e)
        {
            TryHandle(&GenericEventListener::OnEvent, e);
            TryHandleKey(e) || TryHandleMouse(e) || TryHandleApplication(e);
        }

    private:
        inline bool TryHandleKey(Event &e)
        {
            if (!TryHandle(&KeyListener::OnKeyEvent, e))
            {
                return false;
            }
            TryHandle(&KeyPressedListener::OnKeyPressed, e);
            TryHandle(&KeyReleasedListener::OnKeyReleased, e);
            TryHandle(&KeyTypedListener::OnKeyTyped, e);
            return true;
        }

        inline bool TryHandleMouse(Event &e)
        {
            if (!TryHandle(&MouseListener::OnMouseEvent, e))
            {
                return false;
            }
            if (TryHandle(&MouseButtonListener::OnMouseButtonEvent, e))
            {
                TryHandle(&MouseButtonPressedListener::OnMouseButtonPressed, e);
                TryHandle(&MouseButtonReleasedListener::OnMouseButtonReleased, e);
            }
            else
            {
                TryHandle(&MouseWheelListener::OnMouseScrolled, e);
                TryHandle(&MouseMotionListener::OnMouseMoved, e);
            }
            return true;
        }

        inline bool TryHandleApplication(Event &e)
        {
            if (!TryHandle(&ApplicationListener::OnApplicationEvent, e))
            {
                return false;
            }
            TryHandle(&WindowClosedListener::OnWindowClosed, e);
            TryHandle(&WindowResizedListener::OnWindowResized, e);
            return true;
        }

        template<typename L, typename E>
        inline bool TryHandle(void (L:: *method)(E &), Event &e)
        {
            if (e.IsHandled())
            {
                return false;
            }
            L *object = dynamic_cast<L *>(&listener);
            E *event = dynamic_cast<E *>(&e);
            if (object && event)
            {
                (object->*method)(*event);
            }
            return event;
        }
    };
}