#pragma once

#include "EventListener.h"

namespace Hazel
{
    class HAZEL_API MouseWheelListener : public virtual EventListener
    {
    public:
        virtual ~MouseWheelListener() = default;

        virtual void OnMouseScrolled(MouseScrolledEvent &e) = 0;
    };
}