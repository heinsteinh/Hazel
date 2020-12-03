#pragma once

#include "Hazel/GraphicsContext/IndexFormatHelper.h"
#include "Hazel/GraphicsContext/PrimitiveTopology.h"
#include "Private/BatchVertex.h"

namespace Hazel
{
	struct BatchInfo
	{
		size_t MaxIndexCount = 0;
		size_t MaxVertexCount = 0;
		size_t MaxTextureSlotCount = 0;
		IndexFormat IndexFormat = IndexFormat::UInt32;
		PrimitiveTopology PrimitiveTopology = PrimitiveTopology::Triangles;

		size_t GetIndexBufferSize() const
		{
			return IndexFormatHelper::GetSize(MaxIndexCount, IndexFormat);
		}

		size_t GetVertexBufferSize() const
		{
			return MaxVertexCount * sizeof(BatchVertex);
		}
	};
}