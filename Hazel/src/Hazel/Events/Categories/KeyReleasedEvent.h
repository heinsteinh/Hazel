#pragma once

#include "KeyEvent.h"

namespace Hazel
{
    class HAZEL_API KeyReleasedEvent : public KeyEvent
    {
    public:
        KeyReleasedEvent(Key key)
            : KeyEvent(key)
        {
        }
    };
}