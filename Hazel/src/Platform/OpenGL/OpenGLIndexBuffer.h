#pragma once

#include "Hazel/Renderer/IndexBuffer.h"

namespace Hazel
{
    class OpenGLIndexBuffer : public IndexBuffer
    {
    private:
        unsigned int rendererId = 0;
        int count = 0;

    public:
        OpenGLIndexBuffer(int indexes[], int size);
        virtual ~OpenGLIndexBuffer();

        virtual void Bind() const override;
        virtual void UnBind() const override;
        virtual int GetCount() const override;
    };
}