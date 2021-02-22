#pragma once

#include "Hazel/Rendering/GraphicsContext/GraphicsContext.h"
#include "OpenGLBindingContext.h"
#include "Private/OpenGLContextHandle.h"

struct GLFWwindow;

namespace Hazel
{
	class OpenGLGraphicsContext : public GraphicsContext
	{
	private:
		OpenGLContextHandle handle;
		OpenGLBindingContext context;

	public:
		OpenGLGraphicsContext(GLFWwindow *window);

		virtual std::shared_ptr<GuiRenderer> CreateGuiRenderer() override;
		virtual std::shared_ptr<Framebuffer> CreateFramebuffer(const FramebufferInfo &info) override;
		virtual std::shared_ptr<Shader> CreateShader(const ShaderInfo &info) override;
		virtual std::shared_ptr<IndexBuffer> CreateIndexBuffer(size_t size) override;
		virtual std::shared_ptr<VertexBuffer> CreateVertexBuffer(size_t size) override;
		virtual std::shared_ptr<Texture> CreateTexture(const TextureInfo &info) override;
		virtual void SetViewport(const Box2D &viewport) override;
		virtual void SetClearColor(const glm::vec4 &color) override;
		virtual void Clear(const std::shared_ptr<Framebuffer> &framebuffer = {}) override;
		virtual void DrawIndexed(const DrawCommand &command) override;
		virtual void SwapBuffers() override;
	};
}