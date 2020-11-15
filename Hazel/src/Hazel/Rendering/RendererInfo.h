#pragma once

#include "Hazel/GraphicsContext/GraphicsContext.h"
#include "Hazel/Buffers/IndexFormatHelper.h"

namespace Hazel
{
	struct RendererInfo
	{
		GraphicsContext *GraphicsContext = nullptr;
		IndexFormat IndexFormat = IndexFormat::UInt32;
		size_t VertexSize = 0;
		VertexAttributes VertexAttributes;
		size_t MaxIndices = 0;
		size_t MaxVertices = 0;
		size_t MaxTextures = 0;

		inline std::shared_ptr<IndexBuffer> CreateIndexBuffer() const
		{
			return GraphicsContext->CreateIndexBuffer(MaxIndices * IndexFormatHelper::GetSize(IndexFormat));
		}

		inline std::shared_ptr<VertexBuffer> CreateVertexBuffer() const
		{
			return GraphicsContext->CreateVertexBuffer(MaxVertices * VertexSize);
		}

		inline std::shared_ptr<InputLayout> CreateInputLayout() const
		{
			return GraphicsContext->CreateInputLayout(VertexAttributes);
		}
	};
}