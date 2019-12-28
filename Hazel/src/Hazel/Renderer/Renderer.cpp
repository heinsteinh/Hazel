#include "Renderer.h"

#include "Hazel/Core/Log.h"
#include "Hazel/Renderer/RenderCommand.h"

namespace Hazel
{
    Renderer::Renderer(const Window &window)
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
        const std::shared_ptr<Shader> &shader,
        const std::shared_ptr<VertexArray> &vertexArray,
        const glm::mat4 &transform) const
    {
        shader->Bind();
        shader->UploadUniformMat4("u_ViewProjection", camera->GetViewProjectionMatrix());
        shader->UploadUniformMat4("u_Transform", transform);
        vertexArray->Bind();
        RenderCommand(window).DrawIndexed(vertexArray);
    }
}