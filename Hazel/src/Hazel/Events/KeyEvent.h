#pragma once

#include "InputEvent.h"
#include "Hazel/Core/Key.h"

namespace Hazel
{
    class HAZEL_API KeyEvent : public InputEvent
    {
    public:
        KeyEvent() = default;
    };
}