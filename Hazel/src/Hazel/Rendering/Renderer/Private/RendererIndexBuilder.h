#pragma once

#include "Hazel/Rendering/Meshes/IndexArray.h"
#include "RendererIndices.h"

namespace Hazel
{
	class RendererIndexBuilder
	{
	public:
		static void AddIndices(const IndexArray &source, RendererIndices &destination, size_t vertexCount)
		{
			switch (source.GetIndexFormat())
			{
			case IndexFormat::UInt8:
				AddIndices<uint8_t>(source, destination, vertexCount);
				break;
			case IndexFormat::UInt16:
				AddIndices<uint16_t>(source, destination, vertexCount);
				break;
			case IndexFormat::UInt32:
				AddIndices<uint32_t>(source, destination, vertexCount);
				break;
			}
		}

		template<typename IndexType>
		static void AddIndices(const IndexArray &source, RendererIndices &destination, size_t vertexCount)
		{
			source.ForEach<IndexType>([&](size_t index)
			{
				destination.Add<IndexType>(vertexCount + index);
			});
		}
	};
}