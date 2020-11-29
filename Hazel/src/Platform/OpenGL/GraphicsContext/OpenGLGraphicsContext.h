#pragma once

#include "Hazel/GraphicsContext/GraphicsContext.h"
#include "Platform/OpenGL/Framebuffers/OpenGLFramebufferHolder.h"
#include "Platform/OpenGL/Shaders/OpenGLShaderHolder.h"
#include "Platform/OpenGL/GraphicsBuffers/OpenGLBufferHolder.h"
#include "Platform/OpenGL/Textures/OpenGLTextureHolder.h"
#include "Private/OpenGLDrawer.h"

struct GLFWwindow;

namespace Hazel
{
	class OpenGLGraphicsContext : public GraphicsContext
	{
	private:
		static inline thread_local const OpenGLGraphicsContext *currentContext = nullptr;

		GLFWwindow *window = nullptr;
		OpenGLDrawer drawer;
		OpenGLFramebufferHolder framebuffer;
		OpenGLShaderHolder shader;
		OpenGLBufferHolder buffers;
		OpenGLTextureHolder textures;

	public:
		OpenGLGraphicsContext(GLFWwindow *window);

		void MakeCurrent() const;
		void Detach() const;

		virtual std::shared_ptr<ImGuiRenderer> CreateImGuiRenderer() override;
		virtual std::shared_ptr<Framebuffer> CreateFramebuffer(const FramebufferInfo &info) override;
		virtual std::shared_ptr<Shader> CreateShader(const ShaderInfo &info) override;
		virtual std::shared_ptr<IndexBuffer> CreateIndexBuffer(size_t size) override;
		virtual std::shared_ptr<VertexBuffer> CreateVertexBuffer(size_t size) override;
		virtual std::shared_ptr<ConstantBuffer> CreateConstantBuffer(size_t size) override;
		virtual std::shared_ptr<InputLayout> CreateInputLayout(const VertexAttributes &vertexAttributes) override;
		virtual std::shared_ptr<Texture> CreateTexture(const TextureInfo &info) override;
		virtual void SetFramebuffer(const std::shared_ptr<Framebuffer> &framebuffer) override;
		virtual void SetShader(const std::shared_ptr<Shader> &shader) override;
		virtual void SetIndexBuffer(const std::shared_ptr<IndexBuffer> &indexBuffer) override;
		virtual void SetVertexBuffer(const std::shared_ptr<VertexBuffer> &vertexBuffer) override;
		virtual size_t GetMaxConstantBufferBindingCount() override;
		virtual void SetConstantBuffer(const std::shared_ptr<ConstantBuffer> &constantBuffer, uint32_t binding = 0) override;
		virtual void SetInputLayout(const std::shared_ptr<InputLayout> &inputLayout) override;
		virtual size_t GetMaxTextureSlotCount() override;
		virtual void SetTexture(const std::shared_ptr<Texture> &texture, uint32_t slot = 0) override;
		virtual void SetViewport(const Rectangle &viewport) override;
		virtual void SetClearColor(const glm::vec4 &color) override;
		virtual void Clear() override;
		virtual void SetPrimitiveTopology(PrimitiveTopology primitiveTopology) override;
		virtual void SetIndexFormat(IndexFormat indexFormat) override;
		virtual void DrawIndexed(size_t indexCount) override;
		virtual void SwapBuffers() override;
	};
}