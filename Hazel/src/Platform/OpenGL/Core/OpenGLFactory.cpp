#include "OpenGLFactory.h"

#include "OpenGLContext.h"
#include "Platform/OpenGL/Shaders/OpenGLShader.h"
#include "Platform/OpenGL/Buffers/OpenGLVertexArray.h"
#include "Platform/OpenGL/Buffers/OpenGLVertexBuffer.h"
#include "Platform/OpenGL/Buffers/OpenGLIndexBuffer.h"
#include "Platform/OpenGL/Textures/OpenGLTexture2D.h"

namespace Hazel
{
	std::shared_ptr<GraphicsContext> OpenGLFactory::CreateContext(const Window &window)
	{
		return std::make_shared<OpenGLContext>(window);
	}

	std::shared_ptr<Shader> OpenGLFactory::CreateShader(const ShaderInfo &info)
	{
		return std::make_shared<OpenGLShader>(info);
	}

	std::shared_ptr<VertexArray> OpenGLFactory::CreateVertexArray()
	{
		return std::make_shared<OpenGLVertexArray>();
	}

	std::shared_ptr<VertexBuffer> OpenGLFactory::CreateVertexBuffer(size_t size)
	{
		return std::make_shared<OpenGLVertexBuffer>(size);
	}

	std::shared_ptr<IndexBuffer> OpenGLFactory::CreateIndexBuffer(size_t size)
	{
		return std::make_shared<OpenGLIndexBuffer>(size);
	}

	std::shared_ptr<Texture2D> OpenGLFactory::CreateTexture2D(const TextureInfo &info)
	{
		return std::make_shared<OpenGLTexture2D>(info);
	}
}