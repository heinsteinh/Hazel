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
		VertexAttributes(std::initializer_list<VertexAttribute> attributes = {})
			: attributes(attributes)
		{
			CalculateOffsetsAndStride();
		}

		VertexAttributes(const std::vector<VertexAttribute> &attributes)
			: attributes(attributes)
		{
			CalculateOffsetsAndStride();
		}

		const VertexAttribute &GetAttribute(size_t index) const
		{
			return attributes[index];
		}

		constexpr size_t GetStride() const
		{
			return stride;
		}

		size_t GetSize() const
		{
			return attributes.size();
		}

		auto begin() const
		{
			return attributes.begin();
		}

		auto end() const
		{
			return attributes.end();
		}

		const VertexAttribute &operator[](size_t index) const
		{
			return GetAttribute(index);
		}

	private:
		void CalculateOffsetsAndStride()
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