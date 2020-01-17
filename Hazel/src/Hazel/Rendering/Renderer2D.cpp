#include "Renderer2D.h"

#include "RenderCommand.h"

//TEMPORARY
#include "../../Hazel/src/Platform/OpenGL/OpenGLShader.h"

namespace Hazel
{
    Renderer2D::Renderer2D(Window &window)
        : window(window)
    {
        auto &factory = window.GetContext().GetFactory();
        vertexArray = factory.CreateVertexArray();

        auto vertexBuffer = factory.CreateVertexBuffer({
            -0.5f, -0.5f, 0.0f,
             0.5f, -0.5f, 0.0f,
             0.5f,  0.5f, 0.0f,
            -0.5f,  0.5f, 0.0f});

        vertexBuffer->SetLayout({{ShaderDataType::Float3, "a_Position"}});
        vertexArray->AddVertexBuffer(vertexBuffer);
        vertexArray->SetIndexBuffer(factory.CreateIndexBuffer({0, 1, 2, 2, 3, 0}));

        shader = factory.CreateShader("FlatColor", "assets\\shaders\\FlatColor.glsl");
    }

    void Renderer2D::BeginScene(const OrthographicCamera &camera)
    {
        shader->Bind();
        vertexArray->Bind();
        auto openGLShader = std::dynamic_pointer_cast<OpenGLShader>(shader);
        openGLShader->UploadUniformMat4("u_ViewProjection", camera.GetViewProjectionMatrix());
    }

    void Renderer2D::EndScene()
    {
    }

    void Renderer2D::DrawQuad(const Rectangle &rectangle, const glm::vec4 &color)
    {
        auto openGLShader = std::dynamic_pointer_cast<OpenGLShader>(shader);
        openGLShader->UploadUniformFloat4("u_Color", color);
        openGLShader->UploadUniformMat4("u_Transform", rectangle.GetTransform());
        RenderCommand(window).DrawIndexed(vertexArray);
    }
}