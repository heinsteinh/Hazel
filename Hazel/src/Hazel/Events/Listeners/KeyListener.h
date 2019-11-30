#pragma once

#include "EventListener.h"

namespace Hazel
{
    class HAZEL_API KeyListener : public virtual EventListener
    {
    public:
        virtual ~KeyListener() = default;

        virtual void OnKeyEvent(KeyEvent &e) = 0;
    };
}