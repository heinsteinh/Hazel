#pragma once

#include "Hazel/Rendering/Buffers/VertexArray.h"
#include "Vertex.h"
#include "BatchInfo.h"

namespace Hazel
{
	class BatchBuffer
	{
	private:
		std::shared_ptr<VertexArray> vertexArray;
		std::shared_ptr<IndexBuffer> indexBuffer;
		std::shared_ptr<VertexBuffer> vertexBuffer;

	public:
		inline BatchBuffer(const BatchInfo &info)
			: vertexArray(info.Factory.CreateVertexArray()),
			indexBuffer(info.Factory.CreateIndexBuffer(info.MaxIndices * sizeof(unsigned int))),
			vertexBuffer(info.Factory.CreateVertexBuffer(info.MaxVertices * sizeof(Vertex)))
		{
			vertexBuffer->SetLayout(Vertex::Layout);
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

		inline void BufferIndices(const void *data, size_t count)
		{
			indexBuffer->SetData(data, count * sizeof(unsigned int));
		}

		inline void BufferVertices(const void *data, size_t count)
		{
			vertexBuffer->SetData(data, count * sizeof(Vertex));
		}
	};
}