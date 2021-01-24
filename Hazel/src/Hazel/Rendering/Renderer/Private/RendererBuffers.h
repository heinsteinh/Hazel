#pragma once

#include "Hazel/Rendering/Renderer/RendererInfo.h"
#include "Hazel/Rendering/GraphicsContext/DrawCommand.h"
#include "Hazel/Rendering/Shaders/Uniform.h"
#include "RendererBatch.h"

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

		void Bind(DrawCommand &command)
		{
			command.IndexBuffer = indexBuffer;
			command.VertexBuffer = vertexBuffer;
		}

		void BufferIndices(const RendererBatch &batch)
		{
			auto &indices = batch.GetIndices();
			indexBuffer->BufferData(indices.GetData(), indices.GetSize());
		}

		void BufferVertices(const RendererBatch &batch)
		{
			auto &vertices = batch.GetVertices();
			vertexBuffer->BufferData(vertices.GetData(), vertices.GetSize());
		}
	};
}