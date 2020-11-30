#pragma once

#include "BatchInfo.h"
#include "BatchVertex.h"
#include "BatchIndices.h"
#include "BatchConstants.h"
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
		BatchBuffers(GraphicsContext &graphicsContext, const BatchInfo &info)
			: graphicsContext(&graphicsContext),
			indexBuffer(graphicsContext.CreateIndexBuffer(info.GetIndexBufferSize())),
			vertexBuffer(graphicsContext.CreateVertexBuffer(info.GetVertexBufferSize())),
			constantBuffer(graphicsContext.CreateConstantBuffer(sizeof(BatchConstants))),
			inputLayout(graphicsContext.CreateInputLayout(BatchVertex::Attributes))
		{
			graphicsContext.SetIndexBuffer(indexBuffer);
			graphicsContext.SetVertexBuffer(vertexBuffer);
			graphicsContext.SetConstantBuffer(constantBuffer, 0);
			graphicsContext.SetInputLayout(inputLayout);
		}

		void BufferIndices(const BatchIndices &indices)
		{
			indexBuffer->BufferData(indices.GetData(), indices.GetSize());
		}

		void BufferVertices(const BatchArray<BatchVertex> &vertices)
		{
			vertexBuffer->BufferData(vertices.GetData(), vertices.GetSize());
		}

		void BufferConstants(const BatchConstants &constants)
		{
			constantBuffer->BufferData(&constants, sizeof(BatchConstants));
		}
	};
}