#pragma once

#include "Hazel/Utils/Bindable.h"

namespace Hazel
{
    class IndexBuffer : public Bindable
    {
    public:
        static IndexBuffer *Create(unsigned int indexes[], size_t count);

        virtual ~IndexBuffer() = default;

        virtual size_t GetCount() const = 0;
    };
}