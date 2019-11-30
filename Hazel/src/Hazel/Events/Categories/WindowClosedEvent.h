#pragma once

#include "ApplicationEvent.h"

namespace Hazel
{
    class HAZEL_API WindowClosedEvent : public ApplicationEvent
    {
    public:
        WindowClosedEvent()
        {
        }
    };
}