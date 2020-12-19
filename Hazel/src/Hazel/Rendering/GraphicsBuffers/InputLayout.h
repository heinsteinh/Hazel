#pragma once

#include "VertexAttributes.h"

namespace Hazel
{
	class InputLayout
	{
	private:
		VertexAttributes attributes;

	public:
		InputLayout(const VertexAttributes &attributes)
			: attributes(attributes)
		{
		}

		virtual ~InputLayout() = default;

		constexpr const VertexAttributes &GetAttributes() const
		{
			return attributes;
		}
	};
}