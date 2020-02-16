#pragma once

#include "Context.h"

namespace Hazel
{
    class Window;

    class HAZEL_API RenderApi
    {
    public:
        static RenderApi &OpenGL;

        virtual ~RenderApi() = default;

        virtual Context *CreateContext(const Window &window) = 0;
    };
}