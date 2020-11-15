#pragma once

#include "BatchArray.h"

namespace Hazel
{
	template<typename VertexType>
	class BatchVertices
	{
	private:
		BatchArray data;

	public:
		inline BatchVertices(size_t size = 0)
			: data(sizeof(VertexType), size)
		{
		}

		inline size_t GetMaxElementCount() const
		{
			return data.GetMaxElementCount();
		}

		inline void SetMaxElementCount(size_t count)
		{
			data.SetMaxElementCount(count);
		}

		inline size_t GetElementCount() const
		{
			return data.GetElementCount();
		}

		inline void SetElementCount(size_t elementCount)
		{
			data.SetElementCount(elementCount);
		}

		inline void Clear()
		{
			data.Clear();
		}

		inline bool CanContain(size_t elementCount) const
		{
			return data.CanContain(elementCount);
		}

		inline void *Add(const VertexType &vertex)
		{
			return data.Add(&vertex);
		}

		inline const void *GetData() const
		{
			return data.GetData();
		}

		inline size_t GetSize() const
		{
			return data.GetSize();
		}
	};
}