#pragma once

#include "EventListener.h"

namespace Hazel
{
    class HAZEL_API MouseMotionListener : public virtual EventListener
    {
    public:
        virtual ~MouseMotionListener() = default;

        virtual void OnMouseMoved(MouseMovedEvent &e) = 0;
    };
}