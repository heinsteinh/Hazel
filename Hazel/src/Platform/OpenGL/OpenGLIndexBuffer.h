#pragma once

#include "Hazel/Renderer/IndexBuffer.h"

namespace Hazel
{
    class OpenGLIndexBuffer : public IndexBuffer
    {
    private:
        unsigned int rendererId = 0;
        size_t count = 0;

    public:
        OpenGLIndexBuffer(unsigned int indexes[], size_t count);
        virtual ~OpenGLIndexBuffer();

        virtual void Bind() const override;
        virtual void UnBind() const override;
        virtual size_t GetCount() const override;
    };
}