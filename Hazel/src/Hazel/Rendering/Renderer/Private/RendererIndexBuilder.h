#pragma once

#include "Hazel/Rendering/Mesh/IndexArray.h"
#include "RendererIndices.h"

namespace Hazel
{
	class RendererIndexBuilder
	{
	public:
		static void AddIndices(RendererIndices &destination, const IndexArray &source, size_t vertexCount)
		{
			switch (source.GetIndexFormat())
			{
			case IndexFormat::UInt8:
				AddIndices<uint8_t>(destination, source, vertexCount);
				break;
			case IndexFormat::UInt16:
				AddIndices<uint16_t>(destination, source, vertexCount);
				break;
			case IndexFormat::UInt32:
				AddIndices<uint32_t>(destination, source, vertexCount);
				break;
			}
		}

		template<typename IndexType>
		static void AddIndices(RendererIndices &destination, const IndexArray &source, size_t vertexCount)
		{
			source.ForEach<IndexType>([&](size_t index)
			{
				destination.Add<IndexType>(vertexCount + index);
			});
		}
	};
}