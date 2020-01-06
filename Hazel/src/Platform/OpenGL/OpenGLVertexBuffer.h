#pragma once

#include "Hazel/Rendering/VertexBuffer.h"

namespace Hazel
{
    class OpenGLVertexBuffer : public VertexBuffer
    {
    private:
        size_t size = 0;
        unsigned int id = 0;
        BufferLayout layout;

    public:
        OpenGLVertexBuffer(const std::vector<float> &vertices);
        virtual ~OpenGLVertexBuffer();

        virtual void Bind() const override;
        virtual void UnBind() const override;
        virtual void SetLayout(const BufferLayout &layout) override;
        virtual const BufferLayout &GetLayout() const override;
        virtual size_t GetSize() const override;
    };
}