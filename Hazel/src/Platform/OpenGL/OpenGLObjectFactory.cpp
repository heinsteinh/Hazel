#include "OpenGLObjectFactory.h"

#include "OpenGLShader.h"
#include "OpenGLVertexArray.h"
#include "OpenGLVertexBuffer.h"
#include "OpenGLIndexBuffer.h"
#include "OpenGLTexture2D.h"

#include "Hazel/Utils/Path.h"

namespace Hazel
{
    SharedPtr<Shader> OpenGLObjectFactory::CreateShader(const std::string &name, const std::string &vertexSource, const std::string &fragmentSource)
    {
        return MakeShared<OpenGLShader>(name, vertexSource, fragmentSource);
    }

    SharedPtr<Shader> OpenGLObjectFactory::CreateShader(const std::string &name, const std::string &filename)
    {
        return MakeShared<OpenGLShader>(name, filename);
    }

    SharedPtr<VertexArray> OpenGLObjectFactory::CreateVertexArray()
    {
        return MakeShared<OpenGLVertexArray>();
    }

    SharedPtr<VertexBuffer> OpenGLObjectFactory::CreateVertexBuffer(const std::vector<float> &vertices)
    {
        return MakeShared<OpenGLVertexBuffer>(vertices);
    }

    SharedPtr<IndexBuffer> OpenGLObjectFactory::CreateIndexBuffer(const std::vector<unsigned int> &indexes)
    {
        return MakeShared<OpenGLIndexBuffer>(indexes);
    }

    SharedPtr<Texture2D> OpenGLObjectFactory::CreateTexture2D(int width, int height)
    {
        return MakeShared<OpenGLTexture2D>(width, height);
    }

    SharedPtr<Texture2D> OpenGLObjectFactory::CreateTexture2D(const std::string &filename)
    {
        return MakeShared<OpenGLTexture2D>(filename);
    }
}