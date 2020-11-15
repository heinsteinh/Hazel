#pragma once

#include "Hazel/Buffers/VertexBuffer.h"

namespace Hazel
{
	class OpenGLVertexBuffer : public VertexBuffer
	{
	private:
		uint32_t id = 0;
		size_t size = 0;

	public:
		OpenGLVertexBuffer(size_t size);
		virtual ~OpenGLVertexBuffer();

		void Bind() const;
		void Unbind() const;

		virtual size_t GetSize() const override;
		virtual void BufferData(const void *data, size_t size) override;

		constexpr uint32_t GetId() const
		{
			return id;
		}
	};
}