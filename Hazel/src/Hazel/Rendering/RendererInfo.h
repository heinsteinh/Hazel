#pragma once

#include "Hazel/Graphics/GraphicsContext.h"
#include "Hazel/Buffers/IndexFormatHelper.h"
#include "Vertex.h"

namespace Hazel
{
	struct RendererInfo
	{
		GraphicsContext *GraphicsContext = nullptr;
		IndexFormat IndexFormat = IndexFormat::UInt32;
		size_t MaxIndices = 0;
		size_t MaxVertices = 0;

		inline std::shared_ptr<IndexBuffer> CreateIndexBuffer() const
		{
			return GraphicsContext->CreateIndexBuffer(MaxIndices, IndexFormat);
		}

		inline std::shared_ptr<VertexBuffer> CreateVertexBuffer() const
		{
			return GraphicsContext->CreateVertexBuffer(MaxVertices * sizeof(Vertex));
		}

		inline std::shared_ptr<InputLayout> CreateInputLayout() const
		{
			return GraphicsContext->CreateInputLayout(Vertex::Attributes);
		}
	};
}