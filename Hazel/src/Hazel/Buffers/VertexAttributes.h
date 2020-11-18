#pragma once

#include "VertexAttribute.h"

namespace Hazel
{
	class VertexAttributes
	{
	private:
		std::vector<VertexAttribute> attributes;
		size_t stride = 0;

	public:
		inline VertexAttributes(std::initializer_list<VertexAttribute> attributes = {})
			: attributes(attributes)
		{
			CalculateOffsetsAndStride();
		}

		inline VertexAttributes(const std::vector<VertexAttribute> &attributes)
			: attributes(attributes)
		{
			CalculateOffsetsAndStride();
		}

		inline const VertexAttribute &GetAttribute(size_t index) const
		{
			return attributes[index];
		}

		constexpr size_t GetStride() const
		{
			return stride;
		}

		inline size_t GetSize() const
		{
			return attributes.size();
		}

		inline auto begin() const
		{
			return attributes.begin();
		}

		inline auto end() const
		{
			return attributes.end();
		}

		inline const VertexAttribute &operator[](size_t index) const
		{
			return GetAttribute(index);
		}

	private:
		inline void CalculateOffsetsAndStride()
		{
			stride = 0;
			for (auto &attribute : attributes)
			{
				attribute.SetOffset(stride);
				stride += attribute.GetSize();
			}
		}
	};
}