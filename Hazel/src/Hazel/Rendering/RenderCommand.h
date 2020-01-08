#pragma once

#include "Hazel/Core/Window.h"

namespace Hazel
{
    class HAZEL_API RenderCommand
    {
    private:
        Drawer &drawer;

    public:
        RenderCommand(Window &window)
            : drawer(window.GetContext().GetDrawer())
        {
        }

        inline void SetViewport(const Viewport &viewport) const
        {
            drawer.SetViewport(viewport);
        }

        inline void DrawIndexed(const SharedPtr<VertexArray> &vertexArray) const
        {
            drawer.DrawIndexed(vertexArray);
        }
    };
}