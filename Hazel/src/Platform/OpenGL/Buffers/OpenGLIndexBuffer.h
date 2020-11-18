#pragma once

#include "Hazel/Buffers/IndexBuffer.h"

namespace Hazel
{
	class OpenGLIndexBuffer : public IndexBuffer
	{
	private:
		uint32_t id = 0;

	public:
		OpenGLIndexBuffer(size_t indexCount, IndexFormat indexFormat);
		virtual ~OpenGLIndexBuffer();

		void Bind() const;
		void Unbind() const;

		virtual void BufferData(const void *data, size_t size) override;

		constexpr uint32_t GetId() const
		{
			return id;
		}
	};
}