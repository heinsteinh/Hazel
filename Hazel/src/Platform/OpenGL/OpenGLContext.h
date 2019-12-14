#pragma once

#include "Hazel/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace Hazel
{
    class OpenGLContext : public GraphicsContext
    {
    private:
        GLFWwindow *window = nullptr;

    public:
        OpenGLContext(GLFWwindow *window);

        virtual void SwapBuffers() override;
        virtual void OnUpdate() override;

    private:
        void Init();
    };
}