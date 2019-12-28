#pragma once

#include "Core.h"

namespace Hazel
{
    class HAZEL_API Platform
    {
    public:
        static double GetTime();

        Platform() = delete;
    };
}