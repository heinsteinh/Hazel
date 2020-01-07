#pragma once

#include "Hazel/Rendering/Drawer.h"

namespace Hazel
{
    class HAZEL_API RenderCommand
    {
    private:
        Drawer &drawer;

    public:
        constexpr RenderCommand(Drawer &drawer)
            : drawer(drawer)
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