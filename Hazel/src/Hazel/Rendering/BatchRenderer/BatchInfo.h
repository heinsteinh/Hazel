#pragma once

#include "Hazel/Rendering/GraphicsContext/IndexFormatHelper.h"
#include "Hazel/Rendering/GraphicsContext/PrimitiveTopology.h"
#include "Private/BatchVertex.h"

namespace Hazel
{
	struct BatchInfo
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

		size_t GetVertexBufferSize() const
		{
			return MaxVertexCount * sizeof(BatchVertex);
		}
	};
}