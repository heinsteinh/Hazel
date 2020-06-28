#pragma once

#include "Hazel/Window/Window.h"
#include "Hazel/Rendering/Core/GraphicsContext.h"
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

		virtual SharedPtr<GraphicsContext> CreateContext(const Window &window) = 0;
		virtual SharedPtr<Shader> CreateShader(const ShaderInfo &info) = 0;
		virtual SharedPtr<VertexArray> CreateVertexArray() = 0;
		virtual SharedPtr<VertexBuffer> CreateVertexBuffer(size_t size) = 0;
		virtual SharedPtr<IndexBuffer> CreateIndexBuffer(size_t size) = 0;
		virtual SharedPtr<Texture2D> CreateTexture2D(const TextureInfo &info) = 0;
	};
}