#pragma once

#include "GenericKeyEvent.h"

namespace Hazel
{
    class HAZEL_API KeyReleasedEvent : public GenericKeyEvent
    {
    public:
        KeyReleasedEvent(Key key)
            : GenericKeyEvent(key)
        {
        }
    };
}