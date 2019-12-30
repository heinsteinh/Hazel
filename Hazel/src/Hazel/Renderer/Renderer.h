#pragma once

#include "glm/glm.hpp"

#include "Hazel/Core/Window.h"
#include "Hazel/Renderer/VertexArray.h"
#include "Hazel/Renderer/OrthographicCamera.h"
#include "Hazel/Renderer/Shader.h"

namespace Hazel
{
    class HAZEL_API Renderer
    {
    private:
        Window &window;
        const OrthographicCamera *camera = nullptr;

    public:
        Renderer(Window &window);

        void BeginScene(const OrthographicCamera &camera);
        void EndScene();
        void Submit(
            const SharedPtr<Shader> &shader,
            const SharedPtr<VertexArray> &vertexArray,
            const glm::mat4 &transform = glm::mat4(1.0f)) const;
    };
}