#pragma once

#include "VertexLayout.h"
#include "ByteArray.h"
#include "ConstantVertex.h"
#include "Vertex.h"

namespace Hazel
{
	class VertexArray
	{
	private:
		VertexLayout vertexLayout;
		ByteArray data;

	public:
		VertexArray() = default;

		VertexArray(const VertexLayout &vertexLayout)
			: vertexLayout(vertexLayout),
			data(vertexLayout.GetStride())
		{
		}

		const VertexLayout &GetVertexLayout() const
		{
			return vertexLayout;
		}

		void SetLayout(const VertexLayout &vertexLayout)
		{
			this->vertexLayout = vertexLayout;
			data.SetItemSize(vertexLayout.GetStride());
			Clear();
		}

		const void *GetData() const
		{
			return data.GetData();
		}

		size_t GetSize() const
		{
			return data.GetSize();
		}

		ConstantVertex GetVertex(size_t index) const
		{
			return {vertexLayout, data.GetItem(index)};
		}

		Vertex GetVertex(size_t index)
		{
			return {vertexLayout, data.GetItem(index)};
		}

		size_t GetVertexSize() const
		{
			return data.GetItemSize();
		}

		size_t GetVertexCount() const
		{
			return data.GetItemCount();
		}

		void ReserveVertexCount(size_t vertexCount)
		{
			data.ReserveItemCount(vertexCount);
		}

		void ReserveSize(size_t size)
		{
			data.ReserveSize(size);
		}

		void Clear()
		{
			data.Clear();
		}

		void AddVertex(ConstantVertex vertex)
		{
			data.AddItem(vertex.GetData());
		}

		template<typename T, typename ...Args>
		T &Emplace(Args &&...args)
		{
			return data.Emplace<T>(std::forward<Args>(args)...);
		}

		template<typename FunctorType>
		void ForEach(const FunctorType &functor) const
		{
			data.ForEach([&](const void *vertexData)
			{
				functor(ConstantVertex(vertexLayout, vertexData));
			});
		}

		template<typename FunctorType>
		void ForEach(const FunctorType &functor)
		{
			data.ForEach([&](void *vertexData)
			{
				functor(Vertex(vertexLayout, vertexData));
			});
		}
	};
}