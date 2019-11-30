#pragma once

#include "MouseButtonEvent.h"

namespace Hazel
{
    class HAZEL_API MouseButtonPressedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonPressedEvent(int button)
            : MouseButtonEvent(button)
        {
        }
    };
}