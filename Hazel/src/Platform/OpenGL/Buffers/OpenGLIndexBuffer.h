#pragma once

#include "Hazel/Rendering/Buffers/IndexBuffer.h"

namespace Hazel
{
	class OpenGLIndexBuffer : public IndexBuffer
	{
	private:
		size_t size = 0;
		unsigned int id = 0;

	public:
		OpenGLIndexBuffer(size_t size);
		virtual ~OpenGLIndexBuffer();

		virtual void Bind() const override;
		virtual void Unbind() const override;
		virtual size_t GetSize() const override;
		virtual void SetData(const void *data, size_t size) override;
	};
}