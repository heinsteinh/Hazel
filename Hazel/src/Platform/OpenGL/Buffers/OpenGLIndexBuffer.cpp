#include "OpenGLIndexBuffer.h"

#include "glad/glad.h"

namespace Hazel
{
	OpenGLIndexBuffer::OpenGLIndexBuffer(size_t size)
		: size(size)
	{
		glCreateBuffers(1, &id);
		glNamedBufferData(id, size, nullptr, GL_DYNAMIC_DRAW);
		Log::Info("Index buffer created with id {}.", id);
	}

	OpenGLIndexBuffer::~OpenGLIndexBuffer()
	{
		glDeleteBuffers(1, &id);
		Log::Info("Index buffer with id {} destroyed.", id);
	}

	void OpenGLIndexBuffer::Bind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
	}

	void OpenGLIndexBuffer::Unbind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	size_t OpenGLIndexBuffer::GetSize() const
	{
		return size;
	}

	void OpenGLIndexBuffer::SetData(const void *data, size_t size)
	{
		glNamedBufferSubData(id, 0, std::min(this->size, size), data);
	}
}