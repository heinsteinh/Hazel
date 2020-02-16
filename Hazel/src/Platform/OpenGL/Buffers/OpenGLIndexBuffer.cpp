#include "OpenGLIndexBuffer.h"

#include "glad/glad.h"

namespace Hazel
{
    OpenGLIndexBuffer::OpenGLIndexBuffer(const std::vector<unsigned int> &indexes)
        : size(indexes.size())
    {
        glCreateBuffers(1, &id);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, size * sizeof(unsigned int), indexes.data(), GL_STATIC_DRAW);
    }

    OpenGLIndexBuffer::~OpenGLIndexBuffer()
    {
        glDeleteBuffers(1, &id);
    }

    void OpenGLIndexBuffer::Bind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
    }

    void OpenGLIndexBuffer::UnBind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    size_t OpenGLIndexBuffer::GetSize() const
    {
        return size;
    }
}