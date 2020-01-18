#include "Renderer.h"

#include "Hazel/Rendering/RenderCommand.h"

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
        shader->Bind();
        shader->Put("u_ViewProjection", camera->GetViewProjectionMatrix());
        shader->Put("u_Transform", transform);
        vertexArray->Bind();
        RenderCommand(window).DrawIndexed(vertexArray);
    }
}