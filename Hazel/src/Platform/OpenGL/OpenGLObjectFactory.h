#pragma once

#include "Hazel/Renderer/ObjectFactory.h"
#include "OpenGLContext.h"
#include "OpenGLShader.h"
#include "OpenGLVertexArray.h"
#include "OpenGLVertexBuffer.h"
#include "OpenGLIndexBuffer.h"

namespace Hazel
{
    class OpenGLObjectFactory : public ObjectFactory
    {
    public:
        virtual Context *CreateContext(const Window &window) override
        {
            return new OpenGLContext(static_cast<GLFWwindow *>(window.GetNativeWindow()));
        }

        virtual Shader *CreateShader(const std::string &vertexSource, const std::string &fragmentSource) override
        {
            return new OpenGLShader(vertexSource, fragmentSource);
        }

        virtual VertexArray *CreateVertexArray() override
        {
            return new OpenGLVertexArray();
        }

        virtual VertexBuffer *CreateVertexBuffer(const std::vector<float> &vertices) override
        {
            return new OpenGLVertexBuffer(vertices);
        }

        virtual IndexBuffer *CreateIndexBuffer(const std::vector<unsigned int> &indexes) override
        {
            return new OpenGLIndexBuffer(indexes);
        }
    };
}