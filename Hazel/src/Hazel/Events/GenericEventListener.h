#pragma once

#include "Categories/Event.h"

namespace Hazel
{
    class HAZEL_API GenericEventListener
    {
    public:
        virtual ~GenericEventListener() = default;

        virtual void OnEvent(Event &e) = 0;
    };
}