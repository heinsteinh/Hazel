#pragma once

#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Hazel/Utils/Bindable.h"

namespace Hazel
{
    class VertexArray : public Bindable
    {
    public:
        virtual ~VertexArray() = default;

        virtual const std::vector<SharedPtr<VertexBuffer>> &GetVertexBuffers() const = 0;
        virtual const SharedPtr<IndexBuffer> &GetIndexBuffer() const = 0;
        virtual void AddVertexBuffer(const SharedPtr<VertexBuffer> &buffer) = 0;
        virtual void SetIndexBuffer(const SharedPtr<IndexBuffer> &buffer) = 0;
    };
}