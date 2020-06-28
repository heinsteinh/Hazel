#pragma once

#include "Hazel/Rendering/Core/RenderApiFactory.h"

namespace Hazel
{
	class OpenGLFactory : public RenderApiFactory
	{
	public:
		virtual SharedPtr<GraphicsContext> CreateContext(const Window &window) override;
		virtual SharedPtr<Shader> CreateShader(const ShaderInfo &info) override;
		virtual SharedPtr<VertexArray> CreateVertexArray() override;
		virtual SharedPtr<VertexBuffer> CreateVertexBuffer(size_t size) override;
		virtual SharedPtr<IndexBuffer> CreateIndexBuffer(size_t size) override;
		virtual SharedPtr<Texture2D> CreateTexture2D(const TextureInfo &info) override;
	};
}