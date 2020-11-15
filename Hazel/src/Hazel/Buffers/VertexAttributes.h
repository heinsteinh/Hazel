#pragma once

#include "VertexAttribute.h"

namespace Hazel
{
	class VertexAttributes
	{
	private:
		std::vector<VertexAttribute> elements;
		size_t stride = 0;

	public:
		inline VertexAttributes(std::initializer_list<VertexAttribute> elements = {})
			: elements(elements)
		{
			CalculateOffsetsAndStride();
		}

		inline VertexAttributes(const std::vector<VertexAttribute> &elements)
			: elements(elements)
		{
			CalculateOffsetsAndStride();
		}

		inline const VertexAttribute &GetElement(size_t index) const
		{
			return elements[index];
		}

		constexpr size_t GetStride() const
		{
			return stride;
		}

		inline size_t GetSize() const
		{
			return elements.size();
		}

		inline auto begin() const
		{
			return elements.begin();
		}

		inline auto end() const
		{
			return elements.end();
		}

		inline const VertexAttribute &operator[](size_t index) const
		{
			return GetElement(index);
		}

	private:
		inline void CalculateOffsetsAndStride()
		{
			stride = 0;
			for (auto &element : elements)
			{
				element.SetOffset(stride);
				stride += element.GetSize();
			}
		}
	};
}