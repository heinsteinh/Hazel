#pragma once

#include "VertexHelper.h"
#include "Vertex.h"

namespace Hazel
{
	class ConstantVertex
	{
	private:
		const VertexLayout *layout = nullptr;
		const void *data = nullptr;

	public:
		ConstantVertex(const VertexLayout &layout, const void *data)
			: layout(&layout),
			data(data)
		{
		}

		ConstantVertex(const Vertex &vertex)
			: layout(&vertex.GetLayout()),
			data(vertex.GetData())
		{
		}

		const VertexLayout &GetLayout() const
		{
			return *layout;
		}

		const void *GetData() const
		{
			return data;
		}

		size_t GetSize() const
		{
			return layout->GetStride();
		}

		size_t GetAttributeCount() const
		{
			return layout->GetAttributeCount();
		}

		const void *GetAttribute(size_t index) const
		{
			return VertexHelper::GetAttribute(*layout, data, index);
		}

		template<typename T>
		const T &As() const
		{
			return VertexHelper::Convert<T>(*layout, data);
		}

		template<typename T>
		const T &GetAttribute(size_t index) const
		{
			return VertexHelper::GetAttribute<T>(*layout, data, index);
		}
	};
}