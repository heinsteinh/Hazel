#pragma once

#include "Hazel/Buffers/ConstantBuffer.h"

namespace Hazel
{
	class OpenGLUniformBuffer : public ConstantBuffer
	{
	private:
		uint32_t id = 0;

	public:
		OpenGLUniformBuffer(size_t size);
		virtual ~OpenGLUniformBuffer();

		void Bind() const;
		void Unbind() const;

		virtual void BufferData(const void *data, size_t size) override;
	};
}