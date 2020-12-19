#pragma once

#include "Hazel/Core/Gui/GuiRenderer.h"
#include "Hazel/Core/Geometry/Rectangle.h"
#include "Hazel/Rendering/Framebuffers/Framebuffer.h"
#include "Hazel/Rendering/Shaders/Shader.h"
#include "Hazel/Rendering/GraphicsBuffers/IndexBuffer.h"
#include "Hazel/Rendering/GraphicsBuffers/VertexBuffer.h"
#include "Hazel/Rendering/GraphicsBuffers/ConstantBuffer.h"
#include "Hazel/Rendering/GraphicsBuffers/InputLayout.h"
#include "Hazel/Rendering/Textures/Texture.h"
#include "PrimitiveTopology.h"
#include "IndexFormatHelper.h"

namespace Hazel
{
	class GraphicsContext
	{
	public:
		virtual ~GraphicsContext() = default;

		virtual std::shared_ptr<GuiRenderer> CreateGuiRenderer() = 0;
		virtual std::shared_ptr<Framebuffer> CreateFramebuffer(const FramebufferInfo &info) = 0;
		virtual std::shared_ptr<Shader> CreateShader(const ShaderInfo &info) = 0;
		virtual std::shared_ptr<IndexBuffer> CreateIndexBuffer(size_t size) = 0;
		virtual std::shared_ptr<VertexBuffer> CreateVertexBuffer(size_t size) = 0;
		virtual std::shared_ptr<ConstantBuffer> CreateConstantBuffer(size_t size) = 0;
		virtual std::shared_ptr<InputLayout> CreateInputLayout(const VertexAttributes &vertexAttributes) = 0;
		virtual std::shared_ptr<Texture> CreateTexture(const TextureInfo &info) = 0;
		virtual void SetFramebuffer(Framebuffer *framebuffer) = 0;
		virtual void SetShader(Shader *shader) = 0;
		virtual void SetIndexBuffer(IndexBuffer *indexBuffer) = 0;
		virtual void SetVertexBuffer(VertexBuffer *vertexBuffer) = 0;
		virtual size_t GetMaxConstantBufferBindingCount() = 0;
		virtual void SetConstantBuffer(ConstantBuffer *constantBuffer, size_t binding = 0) = 0;
		virtual void SetInputLayout(InputLayout *inputLayout) = 0;
		virtual size_t GetMaxTextureSlotCount() = 0;
		virtual void SetTexture(Texture *texture, size_t slot = 0) = 0;
		virtual void SetViewport(const Rectangle &viewport) = 0;
		virtual void SetClearColor(const glm::vec4 &color) = 0;
		virtual void Clear() = 0;
		virtual void SetPrimitiveTopology(PrimitiveTopology primitiveTopology) = 0;
		virtual void SetIndexFormat(IndexFormat indexFormat) = 0;
		virtual void DrawIndexed(size_t indexCount) = 0;
		virtual void SwapBuffers() = 0;
	};
}