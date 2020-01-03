#include "OpenGLObjectFactory.h"

#include "OpenGLShader.h"
#include "OpenGLVertexArray.h"
#include "OpenGLVertexBuffer.h"
#include "OpenGLIndexBuffer.h"
#include "OpenGLTexture2D.h"

#include "Hazel/Utils/Path.h"

namespace Hazel
{
    SharedPtr<Shader> OpenGLObjectFactory::CreateShader(
        const std::string &name,
        const std::string &vertexSource,
        const std::string &fragmentSource)
    {
        return std::make_shared<OpenGLShader>(name, vertexSource, fragmentSource);
    }

    SharedPtr<Shader> OpenGLObjectFactory::CreateShader(
        const std::string &filename)
    {
        return std::make_shared<OpenGLShader>(Path(filename).GetFilename(), filename);
    }

    SharedPtr<Shader> OpenGLObjectFactory::CreateShader(
        const std::string &name,
        const std::string &filename)
    {
        return std::make_shared<OpenGLShader>(name, filename);
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