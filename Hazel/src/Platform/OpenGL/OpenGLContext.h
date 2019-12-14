#pragma once

#include "Hazel/Renderer/Context.h"

struct GLFWwindow;

namespace Hazel
{
    class OpenGLContext : public Context
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