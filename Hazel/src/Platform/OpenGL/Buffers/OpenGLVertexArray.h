#pragma once

#include "Hazel/Rendering/Buffers/VertexArray.h"

namespace Hazel
{
    class OpenGLVertexArray : public VertexArray
    {
    private:
        unsigned int id = 0;
        std::vector<SharedPtr<VertexBuffer>> vertexBuffers;
        SharedPtr<IndexBuffer> indexBuffer;

    public:
        OpenGLVertexArray();
        virtual ~OpenGLVertexArray();

        virtual void Bind() const override;
        virtual void UnBind() const override;

        virtual const std::vector<SharedPtr<VertexBuffer>> &GetVertexBuffers() const override;
        virtual const SharedPtr<IndexBuffer> &GetIndexBuffer() const override;
        virtual void AddVertexBuffer(const SharedPtr<VertexBuffer> &buffer) override;
        virtual void SetIndexBuffer(const SharedPtr<IndexBuffer> &buffer) override;

    private:
        void SetVerticesAttributes(const BufferLayout &layout);
        void AddVertexAttribute(const BufferLayout &layout, size_t index);
    };
}