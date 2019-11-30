#pragma once

#include "MouseButtonEvent.h"

namespace Hazel
{
    class HAZEL_API MouseButtonReleasedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonReleasedEvent(int button)
            : MouseButtonEvent(button)
        {
        }
    };
}