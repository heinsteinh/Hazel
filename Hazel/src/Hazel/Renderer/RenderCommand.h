#pragma once

#include "Hazel/Core/Core.h"

#include "Hazel/Core/Window.h"

namespace Hazel
{
    class HAZEL_API RenderCommand
    {
    private:
        Window &window;

    public:
        constexpr RenderCommand(Window &window)
            : window(window)
        {
        }

        inline void DrawIndexed(const SharedPtr<VertexArray> &vertexArray) const
        {
            window.GetContext().GetDrawer().DrawIndexed(vertexArray);
        }
    };
}