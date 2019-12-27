#pragma once

#include "glm/glm.hpp"

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

        virtual void SwapBuffers() const override;
        virtual void SetViewport(int width, int height) const override;
        virtual void SetClearColor(const glm::vec4 &color) const override;
        virtual void Clear() const override;
        virtual void DrawIndexed(const std::shared_ptr<VertexArray> &vertexArray) const override;
        virtual Shader *CreateShader(const std::string &vertexSource, const std::string &fragmentSource) const override;
        virtual VertexArray *CreateVertexArray() const override;
        virtual VertexBuffer *CreateVertexBuffer(const std::vector<float> &vertices) const override;
        virtual IndexBuffer *CreateIndexBuffer(const std::vector<unsigned int> &indexes) const override;

    private:
        void Init();
    };
}