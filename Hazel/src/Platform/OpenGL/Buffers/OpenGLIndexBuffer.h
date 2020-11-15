#pragma once

#include "Hazel/Buffers/IndexBuffer.h"

namespace Hazel
{
	class OpenGLIndexBuffer : public IndexBuffer
	{
	private:
		size_t size = 0;
		uint32_t id = 0;

	public:
		OpenGLIndexBuffer(size_t size);
		virtual ~OpenGLIndexBuffer();

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