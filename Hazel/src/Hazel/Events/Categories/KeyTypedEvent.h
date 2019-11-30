#pragma once

#include "KeyEvent.h"

namespace Hazel
{
    class HAZEL_API KeyTypedEvent : public KeyEvent
    {
    public:
        KeyTypedEvent(Key key)
            : KeyEvent(key)
        {
        }
    };
}