#include "OpenGLIndexBuffer.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace Hazel
{
    OpenGLIndexBuffer::OpenGLIndexBuffer(int indexes[], int count)
        : count(count)
    {
        glCreateBuffers(1, &rendererId);
        Bind();
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(int), indexes, GL_STATIC_DRAW);
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

    int OpenGLIndexBuffer::GetCount() const
    {
        return count;
    }
}