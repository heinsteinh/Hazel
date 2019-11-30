#pragma once

#include "EventListener.h"

namespace Hazel
{
    class HAZEL_API KeyReleasedListener : public virtual EventListener
    {
    public:
        virtual ~KeyReleasedListener() = default;

        virtual void OnKeyReleased(KeyReleasedEvent &e) = 0;
    };
}