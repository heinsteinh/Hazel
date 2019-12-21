#pragma once

#include "BufferLayout.h"
#include "Hazel/Utils/Bindable.h"

namespace Hazel
{
    class VertexBuffer : public Bindable
    {
    public:
        static VertexBuffer *Create(float vertices[], size_t size);

        virtual ~VertexBuffer() = default;

        virtual void SetLayout(const BufferLayout &layout) = 0;
        virtual const BufferLayout &GetLayout() const = 0;
    };
}