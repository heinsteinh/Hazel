#pragma once

#include "Hazel/Core/Core.h"
#include "Context.h"
#include "VertexArray.h"

namespace Hazel
{
    class Window;

    class HAZEL_API RenderApi
    {
    public:
        static const RenderApi &OpenGL;

        virtual ~RenderApi() = default;

        virtual Context *CreateContext(const Window &window) const = 0;
    };
}