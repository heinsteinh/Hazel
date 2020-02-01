#pragma once

#include "MouseButtonEvent.h"

namespace Hazel
{
    class HAZEL_API MouseButtonReleasedEvent : public MouseButtonEvent
    {
    public:
        constexpr MouseButtonReleasedEvent(MouseButton button)
            : MouseButtonEvent(button)
        {
        }

    protected:
        virtual void Handle(EventListener &listener) override
        {
            listener.OnInputEvent(*this);
            listener.OnMouseEvent(*this);
            listener.OnMouseButtonEvent(*this);
            listener.OnMouseButtonReleased(*this);
        }
    };
}