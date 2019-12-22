#pragma once

#include "Hazel/Core/Core.h"

#include "Renderer.h"

namespace Hazel
{
    class HAZEL_API RenderCommand
    {
    public:
        static inline void DrawIndexed(const std::shared_ptr<VertexArray> &vertexArray)
        {
            Renderer::GetRenderApi().DrawIndexed(vertexArray);
        }

        RenderCommand() = delete;
    };
}