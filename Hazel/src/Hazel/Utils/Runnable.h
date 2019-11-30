#pragma once

#include "Hazel/Core/Core.h"

namespace Hazel
{
    class HAZEL_API Runnable
    {
    public:
        virtual ~Runnable() = default;

        virtual void OnUpdate() = 0;
    };
}