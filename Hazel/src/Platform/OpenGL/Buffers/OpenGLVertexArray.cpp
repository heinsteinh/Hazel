#include "OpenGLVertexArray.h"

#include "glad/glad.h"

#include "Platform/OpenGL/Utils/OpenGLConvert.h"

namespace Hazel
{
    OpenGLVertexArray::OpenGLVertexArray()
    {
        glCreateVertexArrays(1, &id);
    }

    OpenGLVertexArray::~OpenGLVertexArray()
    {
        glDeleteVertexArrays(1, &id);
    }

    void OpenGLVertexArray::Bind() const
    {
        glBindVertexArray(id);
    }

    void OpenGLVertexArray::UnBind() const
    {
        glBindVertexArray(0);
    }

    const std::vector<SharedPtr<VertexBuffer>> &OpenGLVertexArray::GetVertexBuffers() const
    {
        return vertexBuffers;
    }

    const SharedPtr<IndexBuffer> &OpenGLVertexArray::GetIndexBuffer() const
    {
        return indexBuffer;
    }

    void OpenGLVertexArray::AddVertexBuffer(const SharedPtr<VertexBuffer> &buffer)
    {
        vertexBuffers.push_back(buffer);
        glBindVertexArray(id);
        buffer->Bind();
        SetVerticesAttributes(buffer->GetLayout());
    }

    void OpenGLVertexArray::SetIndexBuffer(const SharedPtr<IndexBuffer> &buffer)
    {
        indexBuffer = buffer;
        glBindVertexArray(id);
        buffer->Bind();
    }

    void OpenGLVertexArray::SetVerticesAttributes(const BufferLayout &layout)
    {
        for (size_t i = 0; i < layout.GetSize(); i++)
        {
            glEnableVertexAttribArray((int)i);
            SetVertexAttributes(layout, i);
        }
    }

    void OpenGLVertexArray::SetVertexAttributes(const BufferLayout &layout, size_t index)
    {
        const auto &element = layout.GetElement(index);
        glVertexAttribPointer(
            (int)index,
            (int)element.GetComponentCount(),
            OpenGLConvert::ToInternal(element.GetComponentType()),
            element.IsNormalized() ? GL_TRUE : GL_FALSE,
            (int)layout.GetStride(),
            (const void *)element.GetOffset());
    }
}