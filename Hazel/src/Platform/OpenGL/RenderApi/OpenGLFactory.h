#pragma once

#include "Hazel/RenderApi/RenderApiFactory.h"

namespace Hazel
{
	class OpenGLFactory : public RenderApiFactory
	{
	public:
		virtual std::shared_ptr<GraphicsContext> CreateContext(GLFWwindow *window) override;
		virtual std::shared_ptr<Framebuffer> CreateFramebuffer(const FramebufferInfo &info) override;
		virtual std::shared_ptr<ImGuiDrawer> CreateImGuiDrawer(GLFWwindow *window) override;
		virtual std::shared_ptr<Shader> CreateShader(const ShaderInfo &info) override;
		virtual std::shared_ptr<VertexArray> CreateVertexArray() override;
		virtual std::shared_ptr<VertexBuffer> CreateVertexBuffer(size_t size) override;
		virtual std::shared_ptr<IndexBuffer> CreateIndexBuffer(size_t size) override;
		virtual std::shared_ptr<Texture> CreateTexture(const TextureInfo &info) override;
	};
}