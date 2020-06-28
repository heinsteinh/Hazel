#include "OpenGLFactory.h"

#include "OpenGLContext.h"
#include "Platform/OpenGL/Shaders/OpenGLShader.h"
#include "Platform/OpenGL/Buffers/OpenGLVertexArray.h"
#include "Platform/OpenGL/Buffers/OpenGLVertexBuffer.h"
#include "Platform/OpenGL/Buffers/OpenGLIndexBuffer.h"
#include "Platform/OpenGL/Textures/OpenGLTexture2D.h"

namespace Hazel
{
	SharedPtr<GraphicsContext> OpenGLFactory::CreateContext(const Window &window)
	{
		return MakeShared<OpenGLContext>(window);
	}

	SharedPtr<Shader> OpenGLFactory::CreateShader(const ShaderInfo &info)
	{
		return MakeShared<OpenGLShader>(info);
	}

	SharedPtr<VertexArray> OpenGLFactory::CreateVertexArray()
	{
		return MakeShared<OpenGLVertexArray>();
	}

	SharedPtr<VertexBuffer> OpenGLFactory::CreateVertexBuffer(size_t size)
	{
		return MakeShared<OpenGLVertexBuffer>(size);
	}

	SharedPtr<IndexBuffer> OpenGLFactory::CreateIndexBuffer(size_t size)
	{
		return MakeShared<OpenGLIndexBuffer>(size);
	}

	SharedPtr<Texture2D> OpenGLFactory::CreateTexture2D(const TextureInfo &info)
	{
		return MakeShared<OpenGLTexture2D>(info);
	}
}