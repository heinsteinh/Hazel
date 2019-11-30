#pragma once

#include "EventListener.h"

namespace Hazel
{
    class HAZEL_API GenericEventListener : public virtual EventListener
    {
    public:
        virtual ~GenericEventListener() = default;

        virtual void OnEvent(Event &e) = 0;
    };
}