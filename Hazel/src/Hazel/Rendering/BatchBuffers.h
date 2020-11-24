#pragma once

#include "RendererInfo.h"

namespace Hazel
{
	class BatchBuffers
	{
	private:
		std::shared_ptr<IndexBuffer> indexBuffer;
		std::shared_ptr<VertexBuffer> vertexBuffer;
		std::shared_ptr<ConstantBuffer> constantBuffer;
		std::shared_ptr<InputLayout> inputLayout;

	public:
		inline BatchBuffers(const RendererInfo &info)
			: indexBuffer(info.CreateIndexBuffer()),
			vertexBuffer(info.CreateVertexBuffer()),
			constantBuffer(info.CreateConstantBuffer()),
			inputLayout(info.CreateInputLayout())
		{
		}

		inline void Bind(GraphicsContext &graphicsContext) const
		{
			graphicsContext.SetIndexBuffer(indexBuffer);
			graphicsContext.SetVertexBuffer(vertexBuffer);
			graphicsContext.SetConstantBuffer(constantBuffer, 0);
			graphicsContext.SetInputLayout(inputLayout);
		}

		inline void BufferIndices(const void *data, size_t size)
		{
			indexBuffer->BufferData(data, size);
		}

		inline void BufferVertices(const void *data, size_t size)
		{
			vertexBuffer->BufferData(data, size);
		}

		inline void BufferConstant(const void *data, size_t size)
		{
			constantBuffer->BufferData(data, size);
		}
	};
}