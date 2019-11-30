#pragma once

#include "EventListener.h"

namespace Hazel
{
    class HAZEL_API WindowResizedListener : public virtual EventListener
    {
    public:
        virtual ~WindowResizedListener() = default;

        virtual void OnWindowResized(WindowResizedEvent &e) = 0;
    };
}