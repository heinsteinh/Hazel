#include "Renderer.h"

#include "Hazel/Renderer/RenderCommand.h"

// TEMPORARY
#include "Platform/OpenGL/OpenGLShader.h"

namespace Hazel
{
    Renderer::Renderer(Window &window)
        : window(window)
    {
    }

    void Renderer::BeginScene(const OrthographicCamera &camera)
    {
        this->camera = &camera;
    }

    void Renderer::EndScene()
    {
    }

    void Renderer::Submit(
        const SharedPtr<Shader> &shader,
        const SharedPtr<VertexArray> &vertexArray,
        const glm::mat4 &transform) const
    {
        auto openGLShader = std::dynamic_pointer_cast<OpenGLShader>(shader);
        openGLShader->Bind();
        openGLShader->UploadUniformMat4("u_ViewProjection", camera->GetViewProjectionMatrix());
        openGLShader->UploadUniformMat4("u_Transform", transform);
        vertexArray->Bind();
        RenderCommand(window).DrawIndexed(vertexArray);
    }
}