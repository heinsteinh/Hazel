#pragma once

#include "Hazel/Rendering/Buffers/VertexBuffer.h"

namespace Hazel
{
	class OpenGLVertexBuffer : public VertexBuffer
	{
	private:
		size_t size = 0;
		uint32_t id = 0;
		BufferLayout layout;

	public:
		OpenGLVertexBuffer(size_t size);
		virtual ~OpenGLVertexBuffer();

		virtual void Bind() const override;
		virtual void Unbind() const override;
		virtual size_t GetSize() const override;
		virtual const BufferLayout &GetLayout() const override;
		virtual void SetData(const void *data, size_t size) override;
		virtual void SetLayout(const BufferLayout &layout) override;
	};
}