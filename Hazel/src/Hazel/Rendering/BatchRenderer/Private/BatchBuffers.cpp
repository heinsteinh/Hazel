#include "BatchBuffers.h"

namespace Hazel
{
	BatchBuffers::BatchBuffers(GraphicsContext &graphicsContext, const RendererInfo &info)
		: indexBuffer(graphicsContext.CreateIndexBuffer(info.GetIndexBufferSize())),
		vertexBuffer(graphicsContext.CreateVertexBuffer(info.GetVertexBufferSize(sizeof(BatchVertex)))),
		constantBuffer(graphicsContext.CreateConstantBuffer(sizeof(BatchConstants))),
		inputLayout(graphicsContext.CreateInputLayout(BatchVertex::Attributes))
	{
		graphicsContext.SetIndexBuffer(indexBuffer.get());
		graphicsContext.SetVertexBuffer(vertexBuffer.get());
		graphicsContext.SetConstantBuffer(constantBuffer.get(), 0);
		graphicsContext.SetInputLayout(inputLayout.get());
	}

	void BatchBuffers::BufferIndices(const BatchIndices &indices)
	{
		indexBuffer->BufferData(indices.GetData(), indices.GetSize());
	}

	void BatchBuffers::BufferVertices(const BatchArray<BatchVertex> &vertices)
	{
		vertexBuffer->BufferData(vertices.GetData(), vertices.GetSize());
	}

	void BatchBuffers::BufferConstants(const BatchConstants &constants)
	{
		constantBuffer->BufferData(&constants, sizeof(BatchConstants));
	}
}