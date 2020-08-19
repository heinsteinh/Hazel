#include "OpenGLVertexBuffer.h"

#include "glad/glad.h"

namespace Hazel
{
	OpenGLVertexBuffer::OpenGLVertexBuffer(size_t size)
		: size(size)
	{
		glCreateBuffers(1, &id);
		glNamedBufferData(id, size, nullptr, GL_DYNAMIC_DRAW);
		Log::Info("Vertex buffer created with id {}.", id);
	}

	OpenGLVertexBuffer::~OpenGLVertexBuffer()
	{
		glDeleteBuffers(1, &id);
		Log::Info("Vertex buffer with id {} destroyed.", id);
	}

	void OpenGLVertexBuffer::Bind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, id);
	}

	void OpenGLVertexBuffer::Unbind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	size_t OpenGLVertexBuffer::GetSize() const
	{
		return size;
	}

	const BufferLayout &OpenGLVertexBuffer::GetLayout() const
	{
		return layout;
	}

	void OpenGLVertexBuffer::SetData(const void *data, size_t size)
	{
		glNamedBufferSubData(id, 0, std::min(this->size, size), data);
	}

	void OpenGLVertexBuffer::SetLayout(const BufferLayout &layout)
	{
		this->layout = layout;
	}
}