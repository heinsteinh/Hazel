#pragma once

#include "Hazel/Rendering/GraphicsBuffers/IndexBuffer.h"

namespace Hazel
{
	class OpenGLIndexBuffer : public IndexBuffer
	{
	private:
		uint32_t id = 0;

	public:
		OpenGLIndexBuffer(size_t indexCount);
		virtual ~OpenGLIndexBuffer();

		void Bind() const;
		void Unbind() const;

		virtual void BufferData(const void *data, size_t size) override;
	};
}