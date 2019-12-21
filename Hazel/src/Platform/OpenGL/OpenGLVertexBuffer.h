#pragma once

#include "Hazel/Renderer/VertexBuffer.h"

namespace Hazel
{
    class OpenGLVertexBuffer : public VertexBuffer
    {
    private:
        unsigned int rendererId = 0;
        BufferLayout layout;

    public:
        OpenGLVertexBuffer(float vertices[], size_t size);
        virtual ~OpenGLVertexBuffer();

        virtual void Bind() const override;
        virtual void UnBind() const override;
        virtual void SetLayout(const BufferLayout &layout) override;
        virtual const BufferLayout &GetLayout() const override;
    };
}