#pragma once

#include "MouseButtonEvent.h"

namespace Hazel
{
    class HAZEL_API MouseButtonPressedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonPressedEvent(MouseButton button)
            : MouseButtonEvent(button)
        {
        }

    protected:
        virtual void Handle(EventListener &listener) override
        {
            listener.OnMouseButtonPressed(*this);
        }
    };
}