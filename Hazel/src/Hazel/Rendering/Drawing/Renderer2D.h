#pragma once

#include "Hazel/Core/Window.h"
#include "Hazel/Rendering/Camera/OrthographicCamera.h"
#include "Hazel/Rendering/Buffers/VertexArray.h"
#include "Hazel/Rendering/Shaders/Shader.h"
#include "Hazel/Rendering/Textures/Texture2D.h"

#include "RectangularSprite.h"

namespace Hazel
{
    class Renderer2D
    {
    private:
        Window &window;
        SharedPtr<VertexArray> vertexArray;
        SharedPtr<Shader> shader;
        SharedPtr<Texture2D> whiteTexture;

    public:
        Renderer2D(Window &window);

        void BeginScene(const OrthographicCamera &camera);
        void EndScene();
        void Draw(const RectangularSprite &sprite);

    private:
        void Init();
        void CreateVertexArray();
        void AddVertexBuffer();
        SharedPtr<VertexBuffer> CreateVertexBuffer();
        void SetVertexBufferLayout(const SharedPtr<VertexBuffer> &vertexBuffer);
        void AddIndexBuffer();
        void CreateTextureShader();
        void CreateTexture();
        void FillTexture();
    };
}