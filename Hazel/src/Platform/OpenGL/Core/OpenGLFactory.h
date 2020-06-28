#pragma once

#include "Hazel/Rendering/Core/RenderApiFactory.h"

namespace Hazel
{
	class OpenGLFactory : public RenderApiFactory
	{
	public:
		virtual std::shared_ptr<GraphicsContext> CreateContext(GLFWwindow *window) override;
		virtual std::shared_ptr<Shader> CreateShader(const ShaderInfo &info) override;
		virtual std::shared_ptr<VertexArray> CreateVertexArray() override;
		virtual std::shared_ptr<VertexBuffer> CreateVertexBuffer(size_t size) override;
		virtual std::shared_ptr<IndexBuffer> CreateIndexBuffer(size_t size) override;
		virtual std::shared_ptr<Texture2D> CreateTexture2D(const TextureInfo &info) override;
	};
}