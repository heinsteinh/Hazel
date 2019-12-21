#include "OpenGLVertexBuffer.h"

#include "glad/glad.h"

namespace Hazel
{
    OpenGLVertexBuffer::OpenGLVertexBuffer(float vertices[], size_t size)
    {
        glCreateBuffers(1, &rendererId);
        Bind();
        glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
    }

    OpenGLVertexBuffer::~OpenGLVertexBuffer()
    {
        glDeleteBuffers(1, &rendererId);
    }

    void OpenGLVertexBuffer::Bind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, rendererId);
    }

    void OpenGLVertexBuffer::UnBind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void OpenGLVertexBuffer::SetLayout(const BufferLayout &layout)
    {
        this->layout = layout;
    }

    const BufferLayout &OpenGLVertexBuffer::GetLayout() const
    {
        return layout;
    }
}