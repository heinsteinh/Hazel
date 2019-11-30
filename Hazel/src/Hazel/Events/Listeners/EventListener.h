#pragma once

#include "Hazel/Events/Categories/Categories.h"

namespace Hazel
{
    class HAZEL_API EventListener
    {
    public:
        virtual ~EventListener() = default;
    };
}