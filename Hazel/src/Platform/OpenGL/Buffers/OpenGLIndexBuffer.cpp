#include "OpenGLIndexBuffer.h"

#include "glad/glad.h"

namespace Hazel
{
	OpenGLIndexBuffer::OpenGLIndexBuffer(size_t indexCount, IndexFormat indexFormat)
		: IndexBuffer(indexCount, indexFormat)
	{
		glCreateBuffers(1, &id);
		glNamedBufferData(id, GetSize(), nullptr, GL_DYNAMIC_DRAW);
		Log::Debug("Index buffer created with id {}.", id);
	}

	OpenGLIndexBuffer::~OpenGLIndexBuffer()
	{
		glDeleteBuffers(1, &id);
		Log::Debug("Index buffer with id {} destroyed.", id);
	}

	void OpenGLIndexBuffer::Bind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
	}

	void OpenGLIndexBuffer::Unbind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	void OpenGLIndexBuffer::BufferData(const void *data, size_t size)
	{
		glNamedBufferSubData(id, 0, std::min(GetSize(), size), data);
	}
}