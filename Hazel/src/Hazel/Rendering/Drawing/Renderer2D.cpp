#include "Renderer2D.h"

#include "RenderCommand.h"

namespace Hazel
{
    Renderer2D::Renderer2D(Window &window)
        : window(window)
    {
        Init();
    }

    void Renderer2D::BeginScene(const OrthographicCamera &camera)
    {
        vertexArray->Bind();
        shader->Bind();
        shader->Set("u_ViewProjection", camera.GetViewProjectionMatrix());
        shader->Set("u_Scale", 1.0f);
    }

    void Renderer2D::EndScene()
    {
    }

    void Renderer2D::DrawQuad(const Rectangle &rectangle, const glm::vec4 &color)
    {
        shader->Set("u_Color", color);
        whiteTexture->Bind();
        shader->Set("u_Transform", rectangle.GetTransform());
        RenderCommand(window).DrawIndexed(vertexArray);
    }

    void Renderer2D::DrawQuad(const Rectangle &rectangle, const SharedPtr<Texture> &texture)
    {
        shader->Set("u_Color", glm::vec4(1.0f));
        shader->Set("u_Texture", 0);
        shader->Set("u_Transform", rectangle.GetTransform());
        texture->Bind();
        RenderCommand(window).DrawIndexed(vertexArray);
    }

    void Renderer2D::Init()
    {
        CreateVertexArray();
        CreateTextureShader();
        CreateTexture();
    }

    void Renderer2D::CreateVertexArray()
    {
        vertexArray = window.GetContext().GetFactory().CreateVertexArray();
        AddVertexBuffer();
        AddIndexBuffer();
    }

    void Renderer2D::AddVertexBuffer()
    {
        auto vertexBuffer = CreateVertexBuffer();
        SetVertexBufferLayout(vertexBuffer);
        vertexArray->AddVertexBuffer(CreateVertexBuffer());
    }

    SharedPtr<VertexBuffer> Renderer2D::CreateVertexBuffer()
    {
        return window.GetContext().GetFactory().CreateVertexBuffer({
            -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
             0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
             0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
            -0.5f,  0.5f, 0.0f, 0.0f, 1.0f});
    }

    void Renderer2D::SetVertexBufferLayout(const SharedPtr<VertexBuffer> &vertexBuffer)
    {
        vertexBuffer->SetLayout({
            {"a_Position", ShaderDataType::Float3},
            {"a_TexCoord", ShaderDataType::Float2}});
    }

    void Renderer2D::AddIndexBuffer()
    {
        vertexArray->SetIndexBuffer(
            window.GetContext()
            .GetFactory()
            .CreateIndexBuffer({0, 1, 2, 2, 3, 0}));
    }

    void Renderer2D::CreateTextureShader()
    {
        shader = window.GetContext().GetFactory().CreateShader(
            ShaderInfo::FromFile("assets\\shaders\\Texture.glsl"));
    }

    void Renderer2D::CreateTexture()
    {
        whiteTexture = window.GetContext().GetFactory().CreateTexture2D(
            TextureInfo::FromSize(1, 1));
        FillTexture();
    }

    void Renderer2D::FillTexture()
    {
        unsigned int data = ~0;
        whiteTexture->SetData(&data);
    }
}