#pragma once

#include "Hazel/Renderer/ObjectFactory.h"

struct GLFWwindow;

namespace Hazel
{
    class OpenGLObjectFactory : public ObjectFactory
    {
    private:
        GLFWwindow *window = nullptr;

    public:
        OpenGLObjectFactory(GLFWwindow *window);
        virtual ~OpenGLObjectFactory() = default;

        virtual Shader *CreateShader(
            const std::string &vertexSource,
            const std::string &fragmentSource
        ) override;
        virtual VertexArray *CreateVertexArray() override;
        virtual VertexBuffer *CreateVertexBuffer(const std::vector<float> &vertices) override;
        virtual IndexBuffer *CreateIndexBuffer(const std::vector<unsigned int> &indexes) override;
    };
}