#pragma once

#include "BufferLayout.h"
#include "Hazel/Utils/Bindable.h"

namespace Hazel
{
    class VertexBuffer : public Bindable
    {
    public:
        virtual ~VertexBuffer() = default;

        virtual void SetLayout(const BufferLayout &layout) = 0;
        virtual const BufferLayout &GetLayout() const = 0;
        virtual size_t GetSize() const = 0;
    };
}