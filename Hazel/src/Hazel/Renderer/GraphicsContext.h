#pragma once

#include "Hazel/Core/Core.h"
#include "Hazel/Utils/Runnable.h"

namespace Hazel
{
    class HAZEL_API GraphicsContext : public Runnable
    {
    public:
        virtual ~GraphicsContext() = default;

        virtual void SwapBuffers() = 0;
    };
}