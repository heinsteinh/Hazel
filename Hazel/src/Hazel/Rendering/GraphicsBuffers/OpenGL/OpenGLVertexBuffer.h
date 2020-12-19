#pragma once

#include "Hazel/Rendering/GraphicsBuffers/VertexBuffer.h"

namespace Hazel
{
	class OpenGLVertexBuffer : public VertexBuffer
	{
	private:
		uint32_t id = 0;

	public:
		OpenGLVertexBuffer(size_t size);
		virtual ~OpenGLVertexBuffer();

		void Bind() const;
		void Unbind() const;

		virtual void BufferData(const void *data, size_t size) override;

		constexpr uint32_t GetId() const
		{
			return id;
		}
	};
}