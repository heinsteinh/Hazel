#pragma once

#include "Hazel/Core/Core.h"
#include "Hazel/Utils/Runnable.h"

namespace Hazel
{
    class HAZEL_API Context : public Runnable
    {
    public:
        virtual ~Context() = default;

        virtual void SwapBuffers() = 0;
    };
}