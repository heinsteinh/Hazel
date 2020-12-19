#pragma once

#include "Hazel/Rendering/GraphicsContext/GraphicsContext.h"
#include "Hazel/Rendering/Framebuffers/OpenGL/OpenGLFramebufferHolder.h"
#include "Hazel/Rendering/Shaders/OpenGL/OpenGLShaderHolder.h"
#include "Hazel/Rendering/GraphicsBuffers/OpenGL/OpenGLBufferHolder.h"
#include "Hazel/Rendering/Textures/OpenGL/OpenGLTextureHolder.h"
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

		virtual std::shared_ptr<GuiRenderer> CreateGuiRenderer() override;
		virtual std::shared_ptr<Framebuffer> CreateFramebuffer(const FramebufferInfo &info) override;
		virtual std::shared_ptr<Shader> CreateShader(const ShaderInfo &info) override;
		virtual std::shared_ptr<IndexBuffer> CreateIndexBuffer(size_t size) override;
		virtual std::shared_ptr<VertexBuffer> CreateVertexBuffer(size_t size) override;
		virtual std::shared_ptr<ConstantBuffer> CreateConstantBuffer(size_t size) override;
		virtual std::shared_ptr<InputLayout> CreateInputLayout(const VertexAttributes &vertexAttributes) override;
		virtual std::shared_ptr<Texture> CreateTexture(const TextureInfo &info) override;
		virtual void SetFramebuffer(Framebuffer *framebuffer) override;
		virtual void SetShader(Shader *shader) override;
		virtual void SetIndexBuffer(IndexBuffer *indexBuffer) override;
		virtual void SetVertexBuffer(VertexBuffer *vertexBuffer) override;
		virtual size_t GetMaxConstantBufferBindingCount() override;
		virtual void SetConstantBuffer(ConstantBuffer *constantBuffer, size_t binding = 0) override;
		virtual void SetInputLayout(InputLayout *inputLayout) override;
		virtual size_t GetMaxTextureSlotCount() override;
		virtual void SetTexture(Texture *texture, size_t slot = 0) override;
		virtual void SetViewport(const Rectangle &viewport) override;
		virtual void SetClearColor(const glm::vec4 &color) override;
		virtual void Clear() override;
		virtual void SetPrimitiveTopology(PrimitiveTopology primitiveTopology) override;
		virtual void SetIndexFormat(IndexFormat indexFormat) override;
		virtual void DrawIndexed(size_t indexCount) override;
		virtual void SwapBuffers() override;
	};
}