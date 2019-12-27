#pragma once

#include <vector>

#include "Hazel/Core/Core.h"
#include "Hazel/Core/Window.h"
#include "Hazel/Renderer/VertexArray.h"
#include "Hazel/Renderer/OrthographicCamera.h"
#include "Hazel/Renderer/Shader.h"

namespace Hazel
{
    class HAZEL_API Renderer
    {
    private:
        const Window &window;
        const OrthographicCamera *camera = nullptr;

    public:
        Renderer(const Window &window);

        void BeginScene(const OrthographicCamera &camera);
        void EndScene();
        void Submit(const std::shared_ptr<Shader> &shader, const std::shared_ptr<VertexArray> &vertexArray) const;
    };
}