#pragma once

#include "EventListener.h"

namespace Hazel
{
    class HAZEL_API WindowClosedListener : public virtual EventListener
    {
    public:
        virtual ~WindowClosedListener() = default;

        virtual void OnWindowClosed(WindowClosedEvent &e) = 0;
    };
}