#pragma once

#include "Hazel/Buffers/VertexArray.h"
#include "Hazel/Rendering/Vertex.h"
#include "BatchInfo.h"

namespace Hazel
{
	class BatchBuffer
	{
	private:
		RenderApiFactory &factory;
		std::shared_ptr<VertexArray> vertexArray;
		std::shared_ptr<IndexBuffer> indexBuffer;
		std::shared_ptr<VertexBuffer> vertexBuffer;

	public:
		inline BatchBuffer(RenderApiFactory &factory)
			: factory(factory)
		{
		}

		inline void Init(const BatchInfo &info)
		{
			vertexArray = factory.CreateVertexArray();
			indexBuffer = factory.CreateIndexBuffer(info.MaxIndices * sizeof(uint32_t));
			vertexBuffer = factory.CreateVertexBuffer(info.MaxVertices * sizeof(Vertex));
			vertexBuffer->SetLayout(Vertex::Layout);
			vertexArray->SetIndexBuffer(indexBuffer);
			vertexArray->AddVertexBuffer(vertexBuffer);
		}

		inline void Bind() const
		{
			vertexArray->Bind();
			vertexArray->GetIndexBuffer()->Bind();
			vertexArray->GetVertexBuffers()[0]->Bind();
		}

		inline void BufferIndices(const void *data, size_t count)
		{
			indexBuffer->SetData(data, count * sizeof(uint32_t));
		}

		inline void BufferVertices(const void *data, size_t count)
		{
			vertexBuffer->SetData(data, count * sizeof(Vertex));
		}
	};
}