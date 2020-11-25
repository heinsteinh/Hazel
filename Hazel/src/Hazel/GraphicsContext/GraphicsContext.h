#pragma once

#include "Hazel/ImGui/ImGuiRenderer.h"
#include "Hazel/Framebuffers/Framebuffer.h"
#include "Hazel/Shaders/Shader.h"
#include "Hazel/GraphicsBuffers/IndexBuffer.h"
#include "Hazel/GraphicsBuffers/VertexBuffer.h"
#include "Hazel/GraphicsBuffers/ConstantBuffer.h"
#include "Hazel/GraphicsBuffers/InputLayout.h"
#include "Hazel/Textures/Texture.h"
#include "Hazel/Geometry/Rectangle.h"
#include "PrimitiveTopology.h"
#include "IndexFormatHelper.h"

namespace Hazel
{
	class GraphicsContext
	{
	public:
		virtual ~GraphicsContext() = default;

		virtual std::shared_ptr<ImGuiRenderer> CreateImGuiRenderer() = 0;
		virtual std::shared_ptr<Framebuffer> CreateFramebuffer(const FramebufferInfo &info) = 0;
		virtual std::shared_ptr<Shader> CreateShader(const ShaderInfo &info) = 0;
		virtual std::shared_ptr<IndexBuffer> CreateIndexBuffer(size_t size) = 0;
		virtual std::shared_ptr<VertexBuffer> CreateVertexBuffer(size_t size) = 0;
		virtual std::shared_ptr<ConstantBuffer> CreateConstantBuffer(size_t size) = 0;
		virtual std::shared_ptr<InputLayout> CreateInputLayout(const VertexAttributes &vertexAttributes) = 0;
		virtual std::shared_ptr<Texture> CreateTexture(const TextureInfo &info) = 0;
		virtual void SetFramebuffer(const std::shared_ptr<Framebuffer> &framebuffer) = 0;
		virtual void SetShader(const std::shared_ptr<Shader> &shader) = 0;
		virtual void SetIndexBuffer(const std::shared_ptr<IndexBuffer> &indexBuffer) = 0;
		virtual void SetVertexBuffer(const std::shared_ptr<VertexBuffer> &vertexBuffer) = 0;
		virtual size_t GetMaxConstantBufferBindingCount() = 0;
		virtual void SetConstantBuffer(const std::shared_ptr<ConstantBuffer> &constantBuffer, uint32_t binding = 0) = 0;
		virtual void SetInputLayout(const std::shared_ptr<InputLayout> &inputLayout) = 0;
		virtual size_t GetMaxTextureSlotCount() = 0;
		virtual void SetTexture(const std::shared_ptr<Texture> &texture, uint32_t slot = 0) = 0;
		virtual void SetViewport(const Rectangle &viewport) = 0;
		virtual void SetClearColor(const glm::vec4 &color) = 0;
		virtual void Clear() = 0;
		virtual void SetPrimitiveTopology(PrimitiveTopology primitiveTopology) = 0;
		virtual void SetIndexFormat(IndexFormat indexFormat) = 0;
		virtual void DrawIndexed(size_t indexCount) = 0;
		virtual void SwapBuffers() = 0;
	};
}