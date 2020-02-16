#pragma once

#include "glm/glm.hpp"

#include "Hazel/Rendering/Buffers/VertexArray.h"
#include "Hazel/Utils/Rectangle.h"

namespace Hazel
{
    class Drawer
    {
    public:
        virtual ~Drawer() = default;

        virtual void SwapBuffers() = 0;
        virtual void SetViewport(const Rectangle &viewport) = 0;
        virtual void SetClearColor(const glm::vec4 &color) = 0;
        virtual void Clear() = 0;
        virtual void DrawIndexed(const SharedPtr<VertexArray> &vertexArray) = 0;
    };
}