#pragma once

#include "glm/glm.hpp"

#include "Hazel/Core/Window.h"
#include "Hazel/Rendering/Buffers/VertexArray.h"
#include "Hazel/Rendering/Camera/OrthographicCamera.h"
#include "Hazel/Rendering/Shaders/Shader.h"

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