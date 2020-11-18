#pragma once

#include "Hazel/ImGui/ImGuiRenderer.h"
#include "Hazel/Framebuffer/Framebuffer.h"
#include "Hazel/Shaders/Shader.h"
#include "Hazel/Buffers/VertexBuffer.h"
#include "Hazel/Buffers/InputLayout.h"
#include "Hazel/Buffers/IndexBuffer.h"
#include "Hazel/Textures/Texture.h"
#include "Hazel/Geometry/Rectangle.h"
#include "PrimitiveType.h"

struct GLFWwindow;

namespace Hazel
{
	class GraphicsContext
	{
	public:
		virtual ~GraphicsContext() = default;

		virtual std::shared_ptr<ImGuiRenderer> CreateImGuiRenderer() = 0;
		virtual std::shared_ptr<Framebuffer> CreateFramebuffer(const FramebufferInfo &info) = 0;
		virtual std::shared_ptr<Shader> CreateShader(const ShaderInfo &info) = 0;
		virtual std::shared_ptr<VertexBuffer> CreateVertexBuffer(size_t size) = 0;
		virtual std::shared_ptr<InputLayout> CreateInputLayout(const VertexAttributes &vertexAttributes) = 0;
		virtual std::shared_ptr<IndexBuffer> CreateIndexBuffer(size_t indexCount, IndexFormat indexFormat) = 0;
		virtual std::shared_ptr<Texture> CreateTexture(const TextureInfo &info) = 0;
		virtual void SetFramebuffer(const std::shared_ptr<Framebuffer> &framebuffer) = 0;
		virtual void SetShader(const std::shared_ptr<Shader> &shader) = 0;
		virtual void SetIndexBuffer(const std::shared_ptr<IndexBuffer> &indexBuffer) = 0;
		virtual void SetVertexBuffer(const std::shared_ptr<VertexBuffer> &vertexBuffer) = 0;
		virtual void SetInputLayout(const std::shared_ptr<InputLayout> &inputLayout) = 0;
		virtual void SetTexture(const std::shared_ptr<Texture> &texture, uint32_t slot = 0) = 0;
		virtual size_t GetTextureSlotCount() = 0;
		virtual void SetViewport(const Rectangle &viewport) = 0;
		virtual void SetClearColor(const glm::vec4 &color) = 0;
		virtual void Clear() = 0;
		virtual void DrawIndexed(size_t indexCount, PrimitiveType primitiveType) = 0;
		virtual void SwapBuffers() = 0;
	};
}