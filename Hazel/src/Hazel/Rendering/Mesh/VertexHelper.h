#pragma once

#include "Hazel/Core/Exceptions/AssertionException.h"
#include "VertexLayout.h"

namespace Hazel
{
	class VertexHelper
	{
	public:
		static const void *GetAttribute(const VertexLayout &layout, const void *data, size_t index)
		{
			return static_cast<const char *>(data) + layout.GetAttribute(index).GetOffset();
		}

		static void *GetAttribute(const VertexLayout &layout, void *data, size_t index)
		{
			return static_cast<char *>(data) + layout.GetAttribute(index).GetOffset();
		}

		template<typename T>
		static const T &Convert(const VertexLayout &layout, const void *data)
		{
			HZ_ASSERT(sizeof(T) == layout.GetStride(), "Invalid type");
			return *static_cast<const T *>(data);
		}

		template<typename T>
		static T &Convert(const VertexLayout &layout, void *data)
		{
			HZ_ASSERT(sizeof(T) == layout.GetStride(), "Invalid type");
			return *static_cast<T *>(data);
		}

		template<typename T>
		static const T &GetAttribute(const VertexLayout &layout, const void *data, size_t index)
		{
			HZ_ASSERT(sizeof(T) == layout.GetAttribute(index).GetSize(), "Invalid type");
			return *static_cast<const T *>(GetAttribute(layout, data, index));
		}

		template<typename T>
		static T &GetAttribute(const VertexLayout &layout, void *data, size_t index)
		{
			HZ_ASSERT(sizeof(T) == layout.GetAttribute(index).GetSize(), "Invalid type");
			return *static_cast<T *>(GetAttribute(layout, data, index));
		}
	};
}