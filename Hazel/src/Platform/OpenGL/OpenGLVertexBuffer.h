#pragma once

#include "Hazel/Renderer/VertexBuffer.h"

namespace Hazel
{
    class OpenGLVertexBuffer : public VertexBuffer
    {
    private:
        unsigned int rendererId = 0;

    public:
        OpenGLVertexBuffer(float vertices[], size_t size);
        virtual ~OpenGLVertexBuffer();

        virtual void Bind() const override;
        virtual void UnBind() const override;
    };
}