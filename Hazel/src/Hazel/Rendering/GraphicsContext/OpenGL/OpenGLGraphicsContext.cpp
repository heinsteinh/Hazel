#include "OpenGLGraphicsContext.h"

#include "GLFW/glfw3.h"

#include "Hazel/Rendering/GuiRenderer/OpenGL/OpenGLGuiRenderer.h"
#include "Hazel/Rendering/Framebuffers/OpenGL/OpenGLFramebufferFactory.h"
#include "Hazel/Rendering/Shaders/OpenGL/OpenGLShaderCompiler.h"
#include "OpenGLCommandBinder.h"
#include "Private/OpenGLDrawer.h"
#include "Private/OpenGLInfo.h"

namespace Hazel
{
	OpenGLGraphicsContext::OpenGLGraphicsContext(GLFWwindow *window)
		: GraphicsContext(OpenGLInfo::LoadOpenGLAndGetApiInfo(window)),
		handle(window),
		context(GetTextureSlotCount())
	{
	}

	std::unique_ptr<GuiRenderer> OpenGLGraphicsContext::CreateGuiRenderer()
	{
		handle.MakeCurrent();
		return std::make_unique<OpenGLGuiRenderer>(handle, context);
	}

	std::shared_ptr<Framebuffer> OpenGLGraphicsContext::CreateFramebuffer(const FramebufferInfo &info)
	{
		handle.MakeCurrent();
		return OpenGLFramebufferFactory::CreateFramebuffer(info);
	}

	std::shared_ptr<Shader> OpenGLGraphicsContext::CreateShader(const ShaderInfo &info)
	{
		handle.MakeCurrent();
		return OpenGLShaderCompiler::Compile(info);
	}

	std::shared_ptr<IndexBuffer> OpenGLGraphicsContext::CreateIndexBuffer(size_t size)
	{
		handle.MakeCurrent();
		return std::make_shared<OpenGLIndexBuffer>(size);
	}

	std::shared_ptr<VertexBuffer> OpenGLGraphicsContext::CreateVertexBuffer(size_t size)
	{
		handle.MakeCurrent();
		return std::make_shared<OpenGLVertexBuffer>(size);
	}

	std::shared_ptr<Texture> OpenGLGraphicsContext::CreateTexture(const TextureInfo &info)
	{
		handle.MakeCurrent();
		return std::make_shared<OpenGLTexture>(info);
	}

	void OpenGLGraphicsContext::SetViewport(const Box2D &viewport)
	{
		handle.MakeCurrent();
		OpenGLDrawer::SetViewport(viewport);
	}

	void OpenGLGraphicsContext::SetClearColor(const glm::vec4 &color)
	{
		handle.MakeCurrent();
		OpenGLDrawer::SetClearColor(color);
	}

	void OpenGLGraphicsContext::Clear(const std::shared_ptr<Framebuffer> &framebuffer)
	{
		handle.MakeCurrent();
		context.SetFramebuffer(framebuffer);
		OpenGLDrawer::Clear();
	}

	void OpenGLGraphicsContext::DrawIndexed(const DrawCommand &command)
	{
		handle.MakeCurrent();
		OpenGLCommandBinder::BindCommand(context, command);
		OpenGLDrawer::DrawIndexed(command);
	}

	void OpenGLGraphicsContext::SwapBuffers()
	{
		glfwSwapBuffers(handle);
	}

	void OpenGLGraphicsContext::SetVerticalSynchronization(bool verticalSynchronization)
	{
		handle.MakeCurrent();
		glfwSwapInterval(verticalSynchronization ? 1 : 0);
	}
}