#pragma once

#include "Hazel/Rendering/GraphicsApi/GraphicsApiInfo.h"
#include "Hazel/Rendering/GuiRenderer/GuiRenderer.h"
#include "Hazel/Rendering/Framebuffers/Framebuffer.h"
#include "Hazel/Rendering/Shaders/Shader.h"
#include "Hazel/Rendering/GraphicsBuffers/IndexBuffer.h"
#include "Hazel/Rendering/GraphicsBuffers/VertexBuffer.h"
#include "Hazel/Rendering/Textures/Texture.h"
#include "Hazel/Core/Geometry/Box2D.h"
#include "DrawCommand.h"

namespace Hazel
{
	class GraphicsContext
	{
	private:
		GraphicsApiInfo info;

	public:
		GraphicsContext(const GraphicsApiInfo &info)
			: info(info)
		{
		}

		virtual ~GraphicsContext() = default;

		virtual std::shared_ptr<GuiRenderer> CreateGuiRenderer() = 0;
		virtual std::shared_ptr<Framebuffer> CreateFramebuffer(const FramebufferInfo &info) = 0;
		virtual std::shared_ptr<Shader> CreateShader(const ShaderInfo &info) = 0;
		virtual std::shared_ptr<IndexBuffer> CreateIndexBuffer(size_t size) = 0;
		virtual std::shared_ptr<VertexBuffer> CreateVertexBuffer(size_t size) = 0;
		virtual std::shared_ptr<Texture> CreateTexture(const TextureInfo &info) = 0;
		virtual void SetViewport(const Box2D &viewport) = 0;
		virtual void SetClearColor(const glm::vec4 &color) = 0;
		virtual void Clear(const std::shared_ptr<Framebuffer> &framebuffer = {}) = 0;
		virtual void DrawIndexed(const DrawCommand &command) = 0;
		virtual void SwapBuffers() = 0;

		const GraphicsApiInfo &GetInfo() const
		{
			return info;
		}

		size_t GetTextureSlotCount() const
		{
			return info.TextureSlotCount;
		}

		size_t GetUniformBindingCount() const
		{
			return info.UniformBindingCount;
		}
	};
}