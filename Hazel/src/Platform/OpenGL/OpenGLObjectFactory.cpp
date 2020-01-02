#include "OpenGLObjectFactory.h"

#include "OpenGLShader.h"
#include "OpenGLVertexArray.h"
#include "OpenGLVertexBuffer.h"
#include "OpenGLIndexBuffer.h"
#include "OpenGLTexture2D.h"

namespace Hazel
{
    SharedPtr<Shader> OpenGLObjectFactory::CreateShader(const std::string &filename)
    {
        return std::make_shared<OpenGLShader>(filename);
    }

    SharedPtr<Shader> OpenGLObjectFactory::CreateShader(const std::string &vertexSource, const std::string &fragmentSource)
    {
        return std::make_shared<OpenGLShader>(vertexSource, fragmentSource);
    }

    SharedPtr<VertexArray> OpenGLObjectFactory::CreateVertexArray()
    {
        return std::make_shared<OpenGLVertexArray>();
    }

    SharedPtr<VertexBuffer> OpenGLObjectFactory::CreateVertexBuffer(const std::vector<float> &vertices)
    {
        return std::make_shared<OpenGLVertexBuffer>(vertices);
    }

    SharedPtr<IndexBuffer> OpenGLObjectFactory::CreateIndexBuffer(const std::vector<unsigned int> &indexes)
    {
        return std::make_shared<OpenGLIndexBuffer>(indexes);
    }

    SharedPtr<Texture2D> OpenGLObjectFactory::CreateTexture2D(const std::string &filename)
    {
        return std::make_shared<OpenGLTexture2D>(filename);
    }
}