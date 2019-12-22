#pragma once

#include "Hazel/Utils/Bindable.h"

namespace Hazel
{
    class IndexBuffer : public Bindable
    {
    public:
        virtual ~IndexBuffer() = default;

        virtual size_t GetSize() const = 0;
    };
}