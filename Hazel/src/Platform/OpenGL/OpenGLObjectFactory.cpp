#include "OpenGLObjectFactory.h"

#include "GLFW/glfw3.h"

#include "OpenGLShader.h"
#include "OpenGLVertexArray.h"
#include "OpenGLVertexBuffer.h"
#include "OpenGLIndexBuffer.h"
#include "OpenGLTexture2D.h"

namespace Hazel
{
    OpenGLObjectFactory::OpenGLObjectFactory(Context &context)
        : context(context)
    {
    }

    SharedPtr<Shader> OpenGLObjectFactory::CreateShader(const std::string &vertexSource, const std::string &fragmentSource)
    {
        context.MakeCurrent();
        return std::make_shared<OpenGLShader>(vertexSource, fragmentSource);
    }

    SharedPtr<VertexArray> OpenGLObjectFactory::CreateVertexArray()
    {
        context.MakeCurrent();
        return std::make_shared<OpenGLVertexArray>();
    }

    SharedPtr<VertexBuffer> OpenGLObjectFactory::CreateVertexBuffer(const std::vector<float> &vertices)
    {
        context.MakeCurrent();
        return std::make_shared<OpenGLVertexBuffer>(vertices);
    }

    SharedPtr<IndexBuffer> OpenGLObjectFactory::CreateIndexBuffer(const std::vector<unsigned int> &indexes)
    {
        context.MakeCurrent();
        return std::make_shared<OpenGLIndexBuffer>(indexes);
    }

    SharedPtr<Texture2D> OpenGLObjectFactory::CreateTexture2D(const std::string &filename)
    {
        context.MakeCurrent();
        return std::make_shared<OpenGLTexture2D>(filename);
    }
}