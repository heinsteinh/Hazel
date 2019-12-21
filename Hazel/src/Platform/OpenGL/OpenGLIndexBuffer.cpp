#include "OpenGLIndexBuffer.h"

#include "glad/glad.h"

namespace Hazel
{
    OpenGLIndexBuffer::OpenGLIndexBuffer(unsigned int indexes[], size_t count)
        : count(count)
    {
        glCreateBuffers(1, &rendererId);
        Bind();
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), indexes, GL_STATIC_DRAW);
    }

    OpenGLIndexBuffer::~OpenGLIndexBuffer()
    {
        glDeleteBuffers(1, &rendererId);
    }

    void OpenGLIndexBuffer::Bind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rendererId);
    }

    void OpenGLIndexBuffer::UnBind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    size_t OpenGLIndexBuffer::GetCount() const
    {
        return count;
    }
}