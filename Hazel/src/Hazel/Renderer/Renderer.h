#pragma once

#include <vector>

#include "Hazel/Core/Core.h"
#include "Hazel/Core/Window.h"
#include "Hazel/Renderer/VertexArray.h"

namespace Hazel
{
    class HAZEL_API Renderer
    {
    private:
        const Window &window;

    public:
        Renderer(const Window &window);

        void BeginScene() const;
        void EndScene() const;
        void Submit(const std::shared_ptr<VertexArray> &vertexArray) const;
    };
}