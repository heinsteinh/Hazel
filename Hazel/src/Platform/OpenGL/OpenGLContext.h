#pragma once

#include "glm/glm.hpp"

#include "Hazel/Renderer/Context.h"
#include "OpenGLObjectFactory.h"

struct GLFWwindow;

namespace Hazel
{
    class OpenGLContext : public Context
    {
    private:
        GLFWwindow *window = nullptr;
        OpenGLObjectFactory factory;

    public:
        OpenGLContext(GLFWwindow *window);

        virtual ObjectFactory &GetFactory() override;
        virtual void MakeCurrent() override;
        virtual void SwapBuffers() override;
        virtual void SetViewport(int width, int height) override;
        virtual void SetClearColor(const glm::vec4 &color) override;
        virtual void Clear() override;
        virtual void DrawIndexed(const SharedPtr<VertexArray> &vertexArray) override;

    private:
        void Init();
    };
}