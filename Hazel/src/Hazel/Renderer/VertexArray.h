#pragma once

#include <vector>
#include <memory>

#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Hazel/Utils/Bindable.h"

namespace Hazel
{
    class VertexArray : public Bindable
    {
    public:
        virtual ~VertexArray() = default;

        virtual const std::vector<std::shared_ptr<VertexBuffer>> &GetVertexBuffers() const = 0;
        virtual const std::shared_ptr<IndexBuffer> &GetIndexBuffer() const = 0;
        virtual void AddVertexBuffer(const std::shared_ptr<VertexBuffer> &buffer) = 0;
        virtual void SetIndexBuffer(const std::shared_ptr<IndexBuffer> &buffer) = 0;
    };
}