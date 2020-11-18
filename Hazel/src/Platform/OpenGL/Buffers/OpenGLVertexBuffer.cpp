#include "OpenGLVertexBuffer.h"

#include "glad/glad.h"

namespace Hazel
{
	OpenGLVertexBuffer::OpenGLVertexBuffer(size_t size)
		: VertexBuffer(size)
	{
		glCreateBuffers(1, &id);
		glNamedBufferData(id, size, nullptr, GL_DYNAMIC_DRAW);
		Log::Debug("Vertex buffer created with id {}.", id);
	}

	OpenGLVertexBuffer::~OpenGLVertexBuffer()
	{
		glDeleteBuffers(1, &id);
		Log::Debug("Vertex buffer with id {} destroyed.", id);
	}

	void OpenGLVertexBuffer::Bind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, id);
	}

	void OpenGLVertexBuffer::Unbind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void OpenGLVertexBuffer::BufferData(const void *data, size_t size)
	{
		glNamedBufferSubData(id, 0, std::min(GetSize(), size), data);
	}
}