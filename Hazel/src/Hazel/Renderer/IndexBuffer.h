#pragma once

#include "Hazel/Utils/Bindable.h"

namespace Hazel
{
    class IndexBuffer : public Bindable
    {
    public:
        static IndexBuffer *Create(int indexes[], int count);

        virtual ~IndexBuffer() = default;

        virtual int GetCount() const = 0;
    };
}