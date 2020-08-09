#pragma once

#include "GraphicsContext.h"
#include "ImGuiDrawer.h"
#include "Hazel/Rendering/Shaders/Shader.h"
#include "Hazel/Rendering/Shaders/ShaderInfo.h"
#include "Hazel/Rendering/Buffers/VertexArray.h"
#include "Hazel/Rendering/Buffers/VertexBuffer.h"
#include "Hazel/Rendering/Buffers/IndexBuffer.h"
#include "Hazel/Rendering/Textures/Texture2D.h"
#include "Hazel/Rendering/Textures/TextureInfo.h"

struct GLFWwindow;

namespace Hazel
{
	class RenderApiFactory
	{
	public:
		virtual ~RenderApiFactory() = default;

		virtual std::shared_ptr<GraphicsContext> CreateContext(GLFWwindow *window) = 0;
		virtual std::shared_ptr<ImGuiDrawer> CreateImGuiDrawer(GLFWwindow *window) = 0;
		virtual std::shared_ptr<Shader> CreateShader(const ShaderInfo &info) = 0;
		virtual std::shared_ptr<VertexArray> CreateVertexArray() = 0;
		virtual std::shared_ptr<VertexBuffer> CreateVertexBuffer(size_t size) = 0;
		virtual std::shared_ptr<IndexBuffer> CreateIndexBuffer(size_t size) = 0;
		virtual std::shared_ptr<Texture2D> CreateTexture2D(const TextureInfo &info) = 0;
	};
}