#pragma once

#include "Hazel/Rendering/Renderer/RendererInfo.h"
#include "Hazel/Rendering/GraphicsContext/DrawCommand.h"
#include "RendererIndices.h"
#include "RendererVertices.h"

namespace Hazel
{
	class RendererBuffers
	{
	private:
		GraphicsContext *graphicsContext = nullptr;
		std::shared_ptr<IndexBuffer> indexBuffer;
		std::shared_ptr<VertexBuffer> vertexBuffer;

	public:
		RendererBuffers(const RendererInfo &info)
			: graphicsContext(info.GraphicsContext),
			indexBuffer(info.GraphicsContext->CreateIndexBuffer(info.IndexBufferSize)),
			vertexBuffer(info.GraphicsContext->CreateVertexBuffer(info.VertexBufferSize))
		{
		}

		const std::shared_ptr<IndexBuffer> &GetIndexBuffer() const
		{
			return indexBuffer;
		}

		const std::shared_ptr<VertexBuffer> &GetVertexBuffer() const
		{
			return vertexBuffer;
		}

		void BufferIndices(const RendererIndices &indices)
		{
			indexBuffer->BufferData(indices.GetData(), indices.GetSize());
		}

		void BufferVertices(const RendererVertices &vertices)
		{
			vertexBuffer->BufferData(vertices.GetData(), vertices.GetSize());
		}
	};
}