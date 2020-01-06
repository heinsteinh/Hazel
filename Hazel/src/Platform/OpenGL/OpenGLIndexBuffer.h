#pragma once

#include <vector>

#include "Hazel/Rendering/IndexBuffer.h"

namespace Hazel
{
    class OpenGLIndexBuffer : public IndexBuffer
    {
    private:
        size_t size = 0;
        unsigned int id = 0;

    public:
        OpenGLIndexBuffer(const std::vector<unsigned int> &indexes);
        virtual ~OpenGLIndexBuffer();

        virtual void Bind() const override;
        virtual void UnBind() const override;
        virtual size_t GetSize() const override;
    };
}