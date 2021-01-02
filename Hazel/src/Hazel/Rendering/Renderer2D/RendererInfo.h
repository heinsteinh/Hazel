#pragma once

#include "Hazel/Rendering/GraphicsContext/IndexFormatHelper.h"
#include "Hazel/Rendering/GraphicsContext/PrimitiveTopology.h"

namespace Hazel
{
	struct RendererInfo
	{
		size_t MaxIndexCount = 60000;
		size_t MaxVertexCount = 40000;
		size_t MaxTextureSlotCount = 32;
		IndexFormat IndexFormat = IndexFormat::UInt32;
		PrimitiveTopology PrimitiveTopology = PrimitiveTopology::Triangles;

		size_t GetIndexBufferSize() const
		{
			return IndexFormatHelper::GetSize(MaxIndexCount, IndexFormat);
		}

		size_t GetVertexBufferSize(size_t vertexSize) const
		{
			return MaxVertexCount * vertexSize;
		}
	};
}