#pragma once

#include "BufferElement.h"

namespace Hazel
{
    class HAZEL_API BufferLayout
    {
    private:
        std::vector<BufferElement> elements;
        size_t stride = 0;

    public:
        BufferLayout(std::initializer_list<BufferElement> elements = {})
            : elements(elements)
        {
            CalculateOffsetsAndStride();
        }

        inline const std::vector<BufferElement> &GetElements() const
        {
            return elements;
        }

        inline const BufferElement &GetElement(size_t index) const
        {
            return elements[index];
        }

        inline size_t GetStride() const
        {
            return stride;
        }

        inline size_t GetSize() const
        {
            return elements.size();
        }

        inline auto begin()
        {
            return elements.begin();
        }

        inline auto end()
        {
            return elements.end();
        }

        inline auto begin() const
        {
            return elements.begin();
        }

        inline auto end() const
        {
            return elements.end();
        }

        inline const BufferElement &operator[](size_t index) const
        {
            return GetElement(index);
        }

    private:
        inline void CalculateOffsetsAndStride()
        {
            stride = 0;
            for (auto &element : elements)
            {
                element.SetOffset(stride);
                stride += element.GetSize();
            }
        }
    };
}