#pragma once

#include "Hazel/Core/Window.h"
#include "OrthographicCamera.h"
#include "VertexArray.h"
#include "Shader.h"
#include "Texture.h"

namespace Hazel
{
    class Renderer2D
    {
    private:
        Window &window;
        SharedPtr<VertexArray> vertexArray;
        SharedPtr<Shader> colorShader;
        SharedPtr<Shader> textureShader;

    public:
        Renderer2D(Window &window);

        void BeginScene(const OrthographicCamera &camera);
        void EndScene();
        void DrawQuad(const Rectangle &rectangle, const glm::vec4 &color);
        void DrawQuad(const Rectangle &rectangle, const SharedPtr<Texture> &texture);
    };
}