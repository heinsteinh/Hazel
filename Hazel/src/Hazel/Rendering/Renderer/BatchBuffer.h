#pragma once

#include "Hazel/Rendering/Buffers/VertexArray.h"
#include "BatchInfo.h"

namespace Hazel
{
	class BatchBuffer
	{
	private:
		SharedPtr<VertexArray> vertexArray;
		SharedPtr<IndexBuffer> indexBuffer;
		SharedPtr<VertexBuffer> vertexBuffer;

	public:
		inline BatchBuffer(const BatchInfo &info)
			: vertexArray(info.Factory.CreateVertexArray()),
			indexBuffer(info.Factory.CreateIndexBuffer(info.MaxIndexes)),
			vertexBuffer(info.Factory.CreateVertexBuffer(info.MaxVertices))
		{
			vertexBuffer->SetLayout(info.Layout);
			vertexArray->SetIndexBuffer(indexBuffer);
			vertexArray->AddVertexBuffer(vertexBuffer);
			Bind();
		}

		inline void Bind() const
		{
			vertexArray->Bind();
			vertexArray->GetIndexBuffer()->Bind();
			vertexArray->GetVertexBuffers()[0]->Bind();
		}

		inline void SetIndexes(const void *indexes, size_t size)
		{
			indexBuffer->SetData(indexes, size);
		}

		inline void SetVertices(const void *vertices, size_t size)
		{
			vertexBuffer->SetData(vertices, size);
		}
	};
}