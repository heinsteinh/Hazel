#pragma once

#include "Hazel/Rendering/Drawer.h"

struct GLFWwindow;

namespace Hazel
{
    class OpenGLDrawer : public Drawer
    {
    private:
        GLFWwindow *window = nullptr;

    public:
        OpenGLDrawer(GLFWwindow *window);

        virtual void SwapBuffers() override;
        virtual void SetViewport(const Viewport &viewport) override;
        virtual void SetClearColor(const glm::vec4 &color) override;
        virtual void Clear() override;
        virtual void DrawIndexed(const SharedPtr<VertexArray> &vertexArray) override;
    };
}