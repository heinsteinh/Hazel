#pragma once

#include "Hazel/Core/Core.h"

#include "Hazel/Core/Window.h"

namespace Hazel
{
    class HAZEL_API RenderCommand
    {
    private:
        const Window &window;

    public:
        constexpr RenderCommand(const Window &window)
            : window(window)
        {
        }

        inline void DrawIndexed(const std::shared_ptr<VertexArray> &vertexArray) const
        {
            window.GetContext().DrawIndexed(vertexArray);
        }
    };
}