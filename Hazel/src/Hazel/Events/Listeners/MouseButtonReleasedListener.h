#pragma once

#include "EventListener.h"

namespace Hazel
{
    class HAZEL_API MouseButtonReleasedListener : public virtual EventListener
    {
    public:
        virtual ~MouseButtonReleasedListener() = default;

        virtual void OnMouseButtonReleased(MouseButtonReleasedEvent &e) = 0;
    };
}