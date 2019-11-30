#pragma once

#include "EventListener.h"

namespace Hazel
{
    class HAZEL_API MouseListener : public virtual EventListener
    {
    public:
        virtual ~MouseListener() = default;

        virtual void OnMouseEvent(MouseEvent &e) = 0;
    };
}