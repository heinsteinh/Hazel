#pragma once

#include "GenericKeyEvent.h"

namespace Hazel
{
    class HAZEL_API KeyReleasedEvent : public GenericKeyEvent
    {
    public:
        constexpr KeyReleasedEvent(Key key)
            : GenericKeyEvent(key)
        {
        }

    protected:
        virtual void Handle(EventListener &listener) override
        {
            listener.OnInputEvent(*this);
            listener.OnKeyEvent(*this);
            listener.OnKeyReleased(*this);
        }
    };
}