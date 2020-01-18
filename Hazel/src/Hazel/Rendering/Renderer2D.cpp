#include "Renderer2D.h"

#include "RenderCommand.h"

namespace Hazel
{
    Renderer2D::Renderer2D(Window &window)
        : window(window)
    {
        auto &factory = window.GetContext().GetFactory();
        vertexArray = factory.CreateVertexArray();

        auto vertexBuffer = factory.CreateVertexBuffer({
            -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
             0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
             0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
            -0.5f,  0.5f, 0.0f, 0.0f, 1.0f});

        vertexBuffer->SetLayout({
            {ShaderDataType::Float3, "a_Position"},
            {ShaderDataType::Float2, "a_TexCoord"}});

        vertexArray->AddVertexBuffer(vertexBuffer);
        vertexArray->SetIndexBuffer(factory.CreateIndexBuffer({0, 1, 2, 2, 3, 0}));

        colorShader = factory.CreateShader("FlatColor", "assets\\shaders\\FlatColor.glsl");
        textureShader = factory.CreateShader("Texture", "assets\\shaders\\Texture.glsl");
    }

    void Renderer2D::BeginScene(const OrthographicCamera &camera)
    {
        vertexArray->Bind();
        auto viewProjection = camera.GetViewProjectionMatrix();
        colorShader->Bind();
        colorShader->Put("u_ViewProjection", viewProjection);
        textureShader->Bind();
        textureShader->Put("u_ViewProjection", viewProjection);
    }

    void Renderer2D::EndScene()
    {
    }

    void Renderer2D::DrawQuad(const Rectangle &rectangle, const glm::vec4 &color)
    {
        colorShader->Bind();
        colorShader->Put("u_Color", color);
        colorShader->Put("u_Transform", rectangle.GetTransform());
        RenderCommand(window).DrawIndexed(vertexArray);
    }

    void Renderer2D::DrawQuad(const Rectangle &rectangle, const SharedPtr<Texture> &texture)
    {
        textureShader->Bind();
        textureShader->Put("u_Texture", 0);
        textureShader->Put("u_Transform", rectangle.GetTransform());
        texture->Bind();
        RenderCommand(window).DrawIndexed(vertexArray);
    }
}