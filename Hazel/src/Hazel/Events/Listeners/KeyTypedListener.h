#pragma once

#include "EventListener.h"

namespace Hazel
{
    class HAZEL_API KeyTypedListener : public virtual EventListener
    {
    public:
        virtual ~KeyTypedListener() = default;

        virtual void OnKeyTyped(KeyTypedEvent &e) = 0;
    };
}