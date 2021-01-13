#pragma once

#include "VertexLayout.h"

namespace Hazel
{
	class InputLayout
	{
	private:
		VertexLayout vertexLayout;

	public:
		InputLayout(const VertexLayout &vertexLayout)
			: vertexLayout(vertexLayout)
		{
		}

		virtual ~InputLayout() = default;

		const VertexLayout &GetVertexLayout() const
		{
			return vertexLayout;
		}
	};
}