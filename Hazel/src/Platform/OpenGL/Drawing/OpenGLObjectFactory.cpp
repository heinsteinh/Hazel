#include "OpenGLObjectFactory.h"

#include "Platform/OpenGL/Shaders/OpenGLShader.h"
#include "Platform/OpenGL/Buffers/OpenGLVertexArray.h"
#include "Platform/OpenGL/Buffers/OpenGLVertexBuffer.h"
#include "Platform/OpenGL/Buffers/OpenGLIndexBuffer.h"
#include "Platform/OpenGL/Textures/OpenGLTexture2D.h"

#include "Hazel/Utils/FileInfo.h"

namespace Hazel
{
    SharedPtr<Shader> OpenGLObjectFactory::CreateShader(const ShaderInfo &info)
    {
        return MakeShared<OpenGLShader>(info);
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

    SharedPtr<Texture2D> OpenGLObjectFactory::CreateTexture2D(const TextureInfo &info)
    {
        return MakeShared<OpenGLTexture2D>(info);
    }
}