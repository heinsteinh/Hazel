#include "OpenGLUniformBuffer.h"

#include "glad/glad.h"

#include "Hazel/Logging/Log.h"

namespace Hazel
{
	OpenGLUniformBuffer::OpenGLUniformBuffer(size_t size)
		: ConstantBuffer(size)
	{
		glCreateBuffers(1, &id);
		glNamedBufferData(id, size, nullptr, GL_DYNAMIC_DRAW);
		Log::Debug("OpenGL uniform buffer created with id {}.", id);
	}

	OpenGLUniformBuffer::~OpenGLUniformBuffer()
	{
		glDeleteBuffers(0, &id);
		Log::Debug("OpenGL uniform buffer with id {} destroyed.", id);
	}

	void OpenGLUniformBuffer::SetBinding(uint32_t binding)
	{
		glBindBufferBase(GL_UNIFORM_BUFFER, binding, id);
	}

	void OpenGLUniformBuffer::Bind() const
	{
		glBindBuffer(GL_UNIFORM_BUFFER, id);
	}

	void OpenGLUniformBuffer::Unbind() const
	{
		glBindBuffer(GL_UNIFORM_BUFFER, 0);
	}

	void OpenGLUniformBuffer::BufferData(const void *data, size_t size)
	{
		glNamedBufferSubData(id, 0, std::min(GetSize(), size), data);
	}
}