#pragma once

#include "ShaderDataTypeHelper.h"

namespace Hazel
{
	class VertexAttribute
	{
	private:
		std::string name;
		ShaderDataType type = ShaderDataType::Unknown;
		size_t offset = 0;
		bool normalized = false;

	public:
		VertexAttribute() = default;

		inline VertexAttribute(const std::string &name, ShaderDataType type, bool normalized = false)
			: name(name),
			type(type),
			normalized(normalized)
		{
		}

		constexpr const std::string &GetName() const
		{
			return name;
		}

		constexpr ShaderDataType GetType() const
		{
			return type;
		}

		constexpr size_t GetOffset() const
		{
			return offset;
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

		constexpr void SetOffset(size_t offset)
		{
			this->offset = offset;
		}
	};
}