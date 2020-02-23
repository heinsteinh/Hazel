#include "Renderer2D.h"

#include "RenderCommand.h"
#include "Hazel/Rendering/Textures/TextureBuilder.h"

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

    void Renderer2D::Draw(const RectangularSprite &sprite)
    {
        shader->Set("u_Color", sprite.GetColor());
        shader->Set("u_Texture", 0);
        shader->Set("u_Transform", sprite.GetTransform());
        auto &texture = sprite.GetTexture();
        texture ? texture->Bind() : whiteTexture->Bind();
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
        vertexArray->AddVertexBuffer(vertexBuffer);
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
        whiteTexture = TextureBuilder(window).Build(glm::vec4(1.0f));
    }
}