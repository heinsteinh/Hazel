#pragma once

#include "Hazel/GraphicsContext/GraphicsContext.h"
#include "OpenGLContext.h"

struct GLFWwindow;

namespace Hazel
{
	class OpenGLGraphicsContext : public GraphicsContext
	{
	private:
		static inline thread_local const OpenGLGraphicsContext *currentContext = nullptr;

		GLFWwindow *window = nullptr;
		OpenGLContext context;

	public:
		OpenGLGraphicsContext(GLFWwindow *window);

		void MakeCurrent() const;
		void Detach() const;

		virtual std::shared_ptr<ImGuiRenderer> CreateImGuiRenderer() override;
		virtual std::shared_ptr<Framebuffer> CreateFramebuffer(const FramebufferInfo &info) override;
		virtual std::shared_ptr<Shader> CreateShader(const ShaderInfo &info) override;
		virtual std::shared_ptr<VertexBuffer> CreateVertexBuffer(size_t size) override;
		virtual std::shared_ptr<InputLayout> CreateInputLayout(const VertexAttributes &vertexAttributes) override;
		virtual std::shared_ptr<IndexBuffer> CreateIndexBuffer(size_t size) override;
		virtual std::shared_ptr<Texture> CreateTexture(const TextureInfo &info) override;
		virtual void SetFramebuffer(const std::shared_ptr<Framebuffer> &framebuffer) override;
		virtual void SetShader(const std::shared_ptr<Shader> &shader) override;
		virtual void SetIndexBuffer(const std::shared_ptr<IndexBuffer> &indexBuffer) override;
		virtual void SetVertexBuffer(const std::shared_ptr<VertexBuffer> &vertexBuffer) override;
		virtual void SetInputLayout(const std::shared_ptr<InputLayout> &inputLayout) override;
		virtual size_t GetTextureSlotCount() override;
		virtual void SetTexture(const std::shared_ptr<Texture> &texture, uint32_t slot = 0) override;
		virtual void SetViewport(const Rectangle &viewport) override;
		virtual void SetClearColor(const glm::vec4 &color) override;
		virtual void Clear() override;
		virtual void DrawIndexed(size_t indexCount, IndexFormat indexFormat) override;
		virtual void SwapBuffers() override;

		constexpr GLFWwindow *GetWindowHandle() const
		{
			return window;
		}
	};
}