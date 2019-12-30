#pragma once

#include "ApplicationEvent.h"

namespace Hazel
{
    class HAZEL_API WindowClosedEvent : public ApplicationEvent
    {
    public:
        constexpr WindowClosedEvent() = default;

    protected:
        virtual void Handle(EventListener &listener) override
        {
            listener.OnWindowClosed(*this);
        }
    };
}