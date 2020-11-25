#pragma once

#include "BatchInfo.h"
#include "BatchIndices.h"
#include "BatchVertex.h"

namespace Hazel
{
	class BatchMesh
	{
	private:
		BatchIndices indices;
		BatchArray<BatchVertex> vertices;

	public:
		inline BatchMesh(const BatchInfo &info)
			: indices(info.MaxIndexCount, info.IndexFormat),
			vertices(info.MaxVertexCount)
		{
		}

		inline void Clear()
		{
			indices.Clear();
			vertices.Clear();
		}

		inline const BatchIndices &GetIndices() const
		{
			return indices;
		}

		void AddIndex(uint32_t index)
		{
			indices.Add(static_cast<uint32_t>(vertices.GetElementCount() + index));
		}

		inline const BatchArray<BatchVertex> &GetVertices() const
		{
			return vertices;
		}

		BatchVertex &EmplaceVertex()
		{
			return vertices.Emplace();
		}
	};
}