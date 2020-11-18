#pragma once

#include "Hazel/Buffers/InputLayout.h"

namespace Hazel
{
	class OpenGLVertexArray : public InputLayout
	{
	private:
		uint32_t id;

	public:
		OpenGLVertexArray(const VertexAttributes &vertexAttributes);
		~OpenGLVertexArray();

		void Bind() const;
		void Unbind() const;
		void AddBoundVertexBuffer();

		constexpr uint32_t GetId() const
		{
			return id;
		}
	};
}