#pragma once

#include "BatchInfo.h"
#include "BatchVertex.h"
#include "BatchIndices.h"
#include "Hazel/GraphicsContext/GraphicsContext.h"

namespace Hazel
{
	class BatchBuffers
	{
	private:
		GraphicsContext *graphicsContext = nullptr;
		std::shared_ptr<IndexBuffer> indexBuffer;
		std::shared_ptr<VertexBuffer> vertexBuffer;
		std::shared_ptr<ConstantBuffer> constantBuffer;
		std::shared_ptr<InputLayout> inputLayout;

	public:
		inline BatchBuffers(GraphicsContext &graphicsContext, const BatchInfo &info)
			: graphicsContext(&graphicsContext),
			indexBuffer(graphicsContext.CreateIndexBuffer(info.GetIndexBufferSize())),
			vertexBuffer(graphicsContext.CreateVertexBuffer(info.GetVertexBufferSize())),
			constantBuffer(graphicsContext.CreateConstantBuffer(sizeof(glm::mat4))),
			inputLayout(graphicsContext.CreateInputLayout(BatchVertex::Attributes))
		{
			Bind();
		}

		inline void Bind() const
		{
			graphicsContext->SetIndexBuffer(indexBuffer);
			graphicsContext->SetVertexBuffer(vertexBuffer);
			graphicsContext->SetConstantBuffer(constantBuffer, 0);
			graphicsContext->SetInputLayout(inputLayout);
		}

		inline void BufferIndices(const BatchIndices &indices)
		{
			indexBuffer->BufferData(indices.GetData(), indices.GetSize());
		}

		inline void BufferVertices(const BatchArray<BatchVertex> &vertices)
		{
			vertexBuffer->BufferData(vertices.GetData(), vertices.GetSize());
		}

		inline void BufferViewProjectionMatrix(const glm::mat4 &viewProjection)
		{
			constantBuffer->BufferData(glm::value_ptr(viewProjection), sizeof(glm::mat4));
		}
	};
}