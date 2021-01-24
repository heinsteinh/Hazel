#pragma once

#include "ShaderDataTypeHelper.h"

namespace Hazel
{
	class VertexAttribute
	{
	private:
		ShaderDataType type = ShaderDataType::Unknown;
		size_t offset = 0;
		bool normalized = false;

	public:
		constexpr VertexAttribute() = default;

		constexpr VertexAttribute(ShaderDataType type, bool normalized = false)
			: type(type),
			normalized(normalized)
		{
		}

		constexpr ShaderDataType GetType() const
		{
			return type;
		}

		constexpr size_t GetOffset() const
		{
			return offset;
		}

		constexpr void SetOffset(size_t offset)
		{
			this->offset = offset;
		}

		constexpr bool IsNormalized() const
		{
			return normalized;
		}

		constexpr DataType GetComponentType() const
		{
			return ShaderDataTypeHelper::GetComponentType(type);
		}

		constexpr size_t GetComponentSize() const
		{
			return ShaderDataTypeHelper::GetComponentSize(type);
		}

		constexpr size_t GetComponentCount() const
		{
			return ShaderDataTypeHelper::GetComponentCount(type);
		}

		constexpr size_t GetSize() const
		{
			return ShaderDataTypeHelper::GetSize(type);
		}

		constexpr bool operator==(const VertexAttribute &other) const
		{
			return type == other.type && offset == other.offset && normalized == other.normalized;
		}

		constexpr bool operator!=(const VertexAttribute &other) const
		{
			return !(*this == other);
		}
	};
}