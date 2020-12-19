#include "OpenGLGraphicsContext.h"

#include "GLFW/glfw3.h"

#include "Hazel/Core/Gui/OpenGL/OpenGLImGuiRenderer.h"
#include "Hazel/Rendering/Framebuffers/OpenGL/OpenGLFramebufferBuilder.h"
#include "Hazel/Rendering/Shaders/OpenGL/OpenGLShaderCompiler.h"
#include "Hazel/Rendering/GraphicsBuffers/OpenGL/OpenGLVertexBuffer.h"
#include "Hazel/Rendering/GraphicsBuffers/OpenGL/OpenGLUniformBuffer.h"
#include "Hazel/Rendering/GraphicsBuffers/OpenGL/OpenGLVertexArray.h"
#include "Hazel/Rendering/GraphicsBuffers/OpenGL/OpenGLIndexBuffer.h"
#include "Hazel/Rendering/Textures/OpenGL/OpenGLTexture.h"
#include "Private/OpenGLLoader.h"
#include "Private/OpenGLDrawer.h"
#include "Private/OpenGLInfo.h"

namespace Hazel
{
	OpenGLGraphicsContext::OpenGLGraphicsContext(GLFWwindow *window)
		: window(window)
	{
		MakeCurrent();
		static OpenGLLoader loader;
		buffers.SetMaxUniformBufferBindingCount(OpenGLInfo::GetMaxUniformBufferBindingCount());
		textures.SetMaxTextureSlotCount(OpenGLInfo::GetMaxTextureSlotCount());
	}

	void OpenGLGraphicsContext::MakeCurrent() const
	{
		if (currentContext != this)
		{
			glfwMakeContextCurrent(window);
			currentContext = this;
		}
	}

	void OpenGLGraphicsContext::Detach() const
	{
		if (currentContext == this)
		{
			glfwMakeContextCurrent(nullptr);
			currentContext = nullptr;
		}
	}

	std::shared_ptr<GuiRenderer> OpenGLGraphicsContext::CreateGuiRenderer()
	{
		MakeCurrent();
		return std::make_shared<OpenGLImGuiRenderer>(window);
	}

	std::shared_ptr<Framebuffer> OpenGLGraphicsContext::CreateFramebuffer(const FramebufferInfo &info)
	{
		MakeCurrent();
		return OpenGLFramebufferBuilder::Build(info);
	}

	std::shared_ptr<Shader> OpenGLGraphicsContext::CreateShader(const ShaderInfo &info)
	{
		MakeCurrent();
		return OpenGLShaderCompiler::Compile(info);
	}

	std::shared_ptr<IndexBuffer> OpenGLGraphicsContext::CreateIndexBuffer(size_t size)
	{
		MakeCurrent();
		return std::make_shared<OpenGLIndexBuffer>(size);
	}

	std::shared_ptr<VertexBuffer> OpenGLGraphicsContext::CreateVertexBuffer(size_t size)
	{
		MakeCurrent();
		return std::make_shared<OpenGLVertexBuffer>(size);
	}

	std::shared_ptr<ConstantBuffer> OpenGLGraphicsContext::CreateConstantBuffer(size_t size)
	{
		return std::make_shared<OpenGLUniformBuffer>(size);
	}

	std::shared_ptr<InputLayout> OpenGLGraphicsContext::CreateInputLayout(const VertexAttributes &vertexAttributes)
	{
		MakeCurrent();
		return std::make_shared<OpenGLVertexArray>(vertexAttributes);
	}

	std::shared_ptr<Texture> OpenGLGraphicsContext::CreateTexture(const TextureInfo &info)
	{
		MakeCurrent();
		return std::make_shared<OpenGLTexture>(info);
	}

	void OpenGLGraphicsContext::SetFramebuffer(Framebuffer *framebuffer)
	{
		MakeCurrent();
		this->framebuffer.SetFramebuffer(framebuffer);
	}

	void OpenGLGraphicsContext::SetShader(Shader *shader)
	{
		MakeCurrent();
		this->shader.SetShader(shader);
	}

	void OpenGLGraphicsContext::SetIndexBuffer(IndexBuffer *indexBuffer)
	{
		MakeCurrent();
		this->buffers.SetIndexBuffer(indexBuffer);
	}

	void OpenGLGraphicsContext::SetVertexBuffer(VertexBuffer *vertexBuffer)
	{
		MakeCurrent();
		this->buffers.SetVertexBuffer(vertexBuffer);
	}

	size_t OpenGLGraphicsContext::GetMaxConstantBufferBindingCount()
	{
		return buffers.GetMaxUniformBufferBindingCount();
	}

	void OpenGLGraphicsContext::SetConstantBuffer(ConstantBuffer *constantBuffer, size_t binding)
	{
		MakeCurrent();
		this->buffers.SetConstantBuffer(constantBuffer, binding);
	}

	void OpenGLGraphicsContext::SetInputLayout(InputLayout *inputLayout)
	{
		MakeCurrent();
		this->buffers.SetInputLayout(inputLayout);
	}

	size_t OpenGLGraphicsContext::GetMaxTextureSlotCount()
	{
		return textures.GetMaxTextureSlotCount();
	}

	void OpenGLGraphicsContext::SetTexture(Texture *texture, size_t slot)
	{
		MakeCurrent();
		this->textures.SetTexture(texture, slot);
	}

	void OpenGLGraphicsContext::SetViewport(const Rectangle &viewport)
	{
		MakeCurrent();
		drawer.SetViewport(viewport);
	}

	void OpenGLGraphicsContext::SetClearColor(const glm::vec4 &color)
	{
		MakeCurrent();
		drawer.SetClearColor(color);
	}

	void OpenGLGraphicsContext::Clear()
	{
		MakeCurrent();
		drawer.Clear();
	}

	void OpenGLGraphicsContext::SetPrimitiveTopology(PrimitiveTopology primitiveTopology)
	{
		drawer.SetPrimitiveTopology(primitiveTopology);
	}

	void OpenGLGraphicsContext::SetIndexFormat(IndexFormat indexFormat)
	{
		drawer.SetIndexFormat(indexFormat);
	}

	void OpenGLGraphicsContext::DrawIndexed(size_t indexCount)
	{
		MakeCurrent();
		drawer.DrawIndexed(indexCount);
	}

	void OpenGLGraphicsContext::SwapBuffers()
	{
		glfwSwapBuffers(window);
	}
}