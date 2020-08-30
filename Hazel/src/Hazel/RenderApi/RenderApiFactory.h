#pragma once

#include "Hazel/GraphicsContext/GraphicsContext.h"
#include "Hazel/Framebuffers/Framebuffer.h"
#include "Hazel/ImGui/ImGuiDrawer.h"
#include "Hazel/Shaders/Shader.h"
#include "Hazel/Buffers/VertexArray.h"
#include "Hazel/Buffers/VertexBuffer.h"
#include "Hazel/Buffers/IndexBuffer.h"
#include "Hazel/Textures/Texture.h"

struct GLFWwindow;

namespace Hazel
{
	class RenderApiFactory
	{
	public:
		virtual ~RenderApiFactory() = default;

		virtual std::shared_ptr<GraphicsContext> CreateContext(GLFWwindow *window) = 0;
		virtual std::shared_ptr<Framebuffer> CreateFramebuffer(const FramebufferInfo &info) = 0;
		virtual std::shared_ptr<ImGuiDrawer> CreateImGuiDrawer(GLFWwindow *window) = 0;
		virtual std::shared_ptr<Shader> CreateShader(const ShaderInfo &info) = 0;
		virtual std::shared_ptr<VertexArray> CreateVertexArray() = 0;
		virtual std::shared_ptr<VertexBuffer> CreateVertexBuffer(size_t size) = 0;
		virtual std::shared_ptr<IndexBuffer> CreateIndexBuffer(size_t size) = 0;
		virtual std::shared_ptr<Texture> CreateTexture(const TextureInfo &info) = 0;
	};
}