#pragma once

#include <vector>

#include "VertexAttribute.h"

namespace Hazel
{
	class VertexLayout
	{
	private:
		std::vector<VertexAttribute> attributes;
		size_t stride = 0;

	public:
		VertexLayout(std::initializer_list<VertexAttribute> attributes = {})
			: attributes(attributes)
		{
			CalculateOffsetsAndStride();
		}

		VertexLayout(const std::vector<VertexAttribute> &attributes)
			: attributes(attributes)
		{
			CalculateOffsetsAndStride();
		}

		const VertexAttribute &GetAttribute(size_t index) const
		{
			return attributes[index];
		}

		size_t GetStride() const
		{
			return stride;
		}

		size_t GetAttributeCount() const
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

		bool operator==(const VertexLayout &other) const
		{
			return attributes == other.attributes;
		}

		bool operator!=(const VertexLayout &other) const
		{
			return attributes != other.attributes;
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