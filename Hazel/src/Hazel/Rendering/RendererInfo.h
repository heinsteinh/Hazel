#pragma once

#include "Hazel/GraphicsContext/GraphicsContext.h"
#include "Hazel/GraphicsContext/IndexFormatHelper.h"
#include "Vertex.h"

namespace Hazel
{
	struct RendererInfo
	{
		GraphicsContext *GraphicsContext = nullptr;
		size_t MaxIndexCount = 0;
		size_t MaxVertexCount = 0;
		IndexFormat IndexFormat = IndexFormat::UInt32;

		inline std::shared_ptr<IndexBuffer> CreateIndexBuffer() const
		{
			return GraphicsContext->CreateIndexBuffer(IndexFormatHelper::GetSize(MaxIndexCount, IndexFormat));
		}

		inline std::shared_ptr<VertexBuffer> CreateVertexBuffer() const
		{
			return GraphicsContext->CreateVertexBuffer(MaxVertexCount * sizeof(Vertex));
		}

		inline std::shared_ptr<ConstantBuffer> CreateConstantBuffer() const
		{
			return GraphicsContext->CreateConstantBuffer(sizeof(glm::mat4));
		}

		inline std::shared_ptr<InputLayout> CreateInputLayout() const
		{
			return GraphicsContext->CreateInputLayout(Vertex::Attributes);
		}
	};
}