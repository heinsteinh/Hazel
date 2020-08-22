#pragma once

#include "GraphicsContext.h"
#include "ImGuiDrawer.h"
#include "Hazel/Shaders/Shader.h"
#include "Hazel/Shaders/ShaderInfo.h"
#include "Hazel/Buffers/VertexArray.h"
#include "Hazel/Buffers/VertexBuffer.h"
#include "Hazel/Buffers/IndexBuffer.h"
#include "Hazel/Textures/Texture2D.h"
#include "Hazel/Textures/TextureInfo.h"

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