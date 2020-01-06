#pragma once

#include "Hazel/Core/Window.h"
#include "Hazel/Rendering/RenderApi.h"
#include "OpenGLContext.h"

namespace Hazel
{
    class OpenGLRenderApi : public RenderApi
    {
    public:
        virtual ~OpenGLRenderApi() = default;

        virtual Context *CreateContext(const Window &window) override
        {
            return new OpenGLContext(static_cast<GLFWwindow *>(window.GetNativeWindow()));
        }
    };
}