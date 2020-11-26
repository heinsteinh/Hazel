#pragma once

#include "Hazel/GraphicsContext/IndexFormatHelper.h"
#include "Hazel/GraphicsContext/PrimitiveTopology.h"
#include "BatchVertex.h"

namespace Hazel
{
	struct BatchInfo
	{
		size_t MaxIndexCount = 0;
		size_t MaxVertexCount = 0;
		size_t MaxTextureSlotCount = 0;
		IndexFormat IndexFormat = IndexFormat::UInt32;
		PrimitiveTopology PrimitiveTopology = PrimitiveTopology::Triangles;

		inline size_t GetIndexBufferSize() const
		{
			return IndexFormatHelper::GetSize(MaxIndexCount, IndexFormat);
		}

		inline size_t GetVertexBufferSize() const
		{
			return MaxVertexCount * sizeof(BatchVertex);
		}
	};
}