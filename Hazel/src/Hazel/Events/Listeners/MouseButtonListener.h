#pragma once

#include "EventListener.h"

namespace Hazel
{
    class HAZEL_API MouseButtonListener : public virtual EventListener
    {
    public:
        virtual ~MouseButtonListener() = default;

        virtual void OnMouseButtonEvent(MouseButtonEvent &e) = 0;
    };
}