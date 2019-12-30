#pragma once

#include "InputEvent.h"

namespace Hazel
{
    class HAZEL_API MouseEvent : public InputEvent
    {
    public:
        constexpr MouseEvent() = default;
    };
}