#pragma once

#include "Hazel/Rendering/Mesh/VertexLayout.h"
#include "Hazel/Rendering/Mesh/ByteArray.h"
#include "Hazel/Rendering/Mesh/ConstVertex.h"

namespace Hazel
{
	class RendererVertices
	{
	private:
		size_t vertexCount = 0;
		ByteArray data;

	public:
		RendererVertices() = default;

		RendererVertices(size_t size)
		{
			Resize(size);
		}

		void SetVertexLayout(const VertexLayout &vertexLayout)
		{
			data.SetItemSize(vertexLayout.GetStride());
			Clear();
		}

		size_t GetVertexCount() const
		{
			return vertexCount;
		}

		void Clear()
		{
			vertexCount = 0;
		}

		const void *GetData() const
		{
			return data.GetData();
		}

		size_t GetSize() const
		{
			return vertexCount * data.GetItemSize();
		}

		void Resize(size_t size)
		{
			data.Resize(size);
		}

		bool CanContain(size_t vertexCount) const
		{
			return GetVertexCount() + vertexCount <= GetMaxVertexCount();
		}

		size_t GetMaxVertexCount() const
		{
			return data.GetItemCount();
		}

		size_t GetVertexSize() const
		{
			return data.GetItemSize();
		}

		Vertex Add(ConstVertex vertex)
		{
			HZ_ASSERT(CanContain(1), "Buffer too small");
			HZ_ASSERT(vertex.GetSize() == GetVertexSize(), "Vertex layout mismatch");
			return {vertex.GetLayout(), data.SetItem(vertexCount++, vertex.GetData())};
		}
	};
}