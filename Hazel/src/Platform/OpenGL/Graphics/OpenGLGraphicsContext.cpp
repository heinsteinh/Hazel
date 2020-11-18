#include "OpenGLGraphicsContext.h"

#include "GLFW/glfw3.h"

#include "Platform/OpenGL/ImGui/OpenGLImGuiRenderer.h"
#include "Platform/OpenGL/Framebuffer/OpenGLFramebufferBuilder.h"
#include "Platform/OpenGL/Shaders/OpenGLShaderCompiler.h"
#include "Platform/OpenGL/Buffers/OpenGLVertexBuffer.h"
#include "Platform/OpenGL/Buffers/OpenGLVertexArray.h"
#include "Platform/OpenGL/Buffers/OpenGLIndexBuffer.h"
#include "Platform/OpenGL/Textures/OpenGLTexture.h"
#include "Helpers/OpenGLLoader.h"
#include "Helpers/OpenGLDrawer.h"
#include "Helpers/OpenGLInfo.h"

namespace Hazel
{
	OpenGLGraphicsContext::OpenGLGraphicsContext(GLFWwindow *window)
		: window(window)
	{
		MakeCurrent();
		static OpenGLLoader loader;
		textures.InitTextureSlots(OpenGLInfo::GetMaxTextures());
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

	std::shared_ptr<ImGuiRenderer> OpenGLGraphicsContext::CreateImGuiRenderer()
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

	std::shared_ptr<VertexBuffer> OpenGLGraphicsContext::CreateVertexBuffer(size_t size)
	{
		MakeCurrent();
		return std::make_shared<OpenGLVertexBuffer>(size);
	}

	std::shared_ptr<InputLayout> OpenGLGraphicsContext::CreateInputLayout(const VertexAttributes &vertexAttributes)
	{
		MakeCurrent();
		return std::make_shared<OpenGLVertexArray>(vertexAttributes);
	}

	std::shared_ptr<IndexBuffer> OpenGLGraphicsContext::CreateIndexBuffer(size_t indexCount, IndexFormat indexFormat)
	{
		MakeCurrent();
		return std::make_shared<OpenGLIndexBuffer>(indexCount, indexFormat);
	}

	std::shared_ptr<Texture> OpenGLGraphicsContext::CreateTexture(const TextureInfo &info)
	{
		MakeCurrent();
		return std::make_shared<OpenGLTexture>(info);
	}

	void OpenGLGraphicsContext::SetFramebuffer(const std::shared_ptr<Framebuffer> &framebuffer)
	{
		MakeCurrent();
		this->framebuffer.SetFramebuffer(framebuffer);
	}

	void OpenGLGraphicsContext::SetShader(const std::shared_ptr<Shader> &shader)
	{
		MakeCurrent();
		this->shader.SetShader(shader);
	}

	void OpenGLGraphicsContext::SetIndexBuffer(const std::shared_ptr<IndexBuffer> &indexBuffer)
	{
		MakeCurrent();
		this->buffers.SetIndexBuffer(indexBuffer);
	}

	void OpenGLGraphicsContext::SetVertexBuffer(const std::shared_ptr<VertexBuffer> &vertexBuffer)
	{
		MakeCurrent();
		this->buffers.SetVertexBuffer(vertexBuffer);
	}

	void OpenGLGraphicsContext::SetInputLayout(const std::shared_ptr<InputLayout> &inputLayout)
	{
		MakeCurrent();
		this->buffers.SetInputLayout(inputLayout);
	}

	size_t OpenGLGraphicsContext::GetTextureSlotCount()
	{
		return textures.GetTextureSlotCount();
	}

	void OpenGLGraphicsContext::SetTexture(const std::shared_ptr<Texture> &texture, uint32_t slot)
	{
		MakeCurrent();
		this->textures.SetTexture(texture, slot);
	}

	void OpenGLGraphicsContext::SetViewport(const Rectangle &viewport)
	{
		MakeCurrent();
		OpenGLDrawer::SetViewport(viewport);
	}

	void OpenGLGraphicsContext::SetClearColor(const glm::vec4 &color)
	{
		MakeCurrent();
		OpenGLDrawer::SetClearColor(color);
	}

	void OpenGLGraphicsContext::Clear()
	{
		MakeCurrent();
		OpenGLDrawer::Clear();
	}

	void OpenGLGraphicsContext::DrawIndexed(size_t indexCount, PrimitiveType primitiveType)
	{
		MakeCurrent();
		OpenGLDrawer::DrawIndexed(
			indexCount,
			primitiveType,
			buffers.GetIndexFormat());
	}

	void OpenGLGraphicsContext::SwapBuffers()
	{
		glfwSwapBuffers(window);
	}
}