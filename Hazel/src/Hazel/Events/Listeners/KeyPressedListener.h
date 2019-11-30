#pragma once

#include "EventListener.h"

namespace Hazel
{
    class HAZEL_API KeyPressedListener : public virtual EventListener
    {
    public:
        virtual ~KeyPressedListener() = default;

        virtual void OnKeyPressed(KeyPressedEvent &e) = 0;
    };
}