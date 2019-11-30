#pragma once

#include "EventListener.h"

namespace Hazel
{
    class HAZEL_API MouseButtonPressedListener : public virtual EventListener
    {
    public:
        virtual ~MouseButtonPressedListener() = default;

        virtual void OnMouseButtonPressed(MouseButtonPressedEvent &e) = 0;
    };
}