#pragma once

#include "VertexHelper.h"

namespace Hazel
{
	class Vertex
	{
	private:
		const VertexLayout *layout = nullptr;
		void *data = nullptr;

	public:
		Vertex(const VertexLayout &layout, void *data)
			: layout(&layout),
			data(data)
		{
		}

		const VertexLayout &GetLayout() const
		{
			return *layout;
		}

		void *GetData() const
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

		void *GetAttribute(size_t index) const
		{
			return VertexHelper::GetAttribute(*layout, data, index);
		}

		template<typename T>
		T &As() const
		{
			return VertexHelper::Convert<T>(*layout, data);
		}

		template<typename T>
		T &GetAttribute(size_t index) const
		{
			return VertexHelper::GetAttribute<T>(*layout, data, index);
		}
	};
}