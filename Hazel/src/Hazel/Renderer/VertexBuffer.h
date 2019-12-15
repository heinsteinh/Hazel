#pragma once

#include "Hazel/Utils/Bindable.h"

namespace Hazel
{
    class VertexBuffer : public Bindable
    {
    public:
        static VertexBuffer *Create(float vertices[], size_t size);

        virtual ~VertexBuffer() = default;
    };
}