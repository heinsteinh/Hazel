#include "Renderer.h"

#include "Hazel/Rendering/Drawing/RenderCommand.h"

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
        shader->Set("u_ViewProjection", camera->GetViewProjectionMatrix());
        shader->Set("u_Transform", transform);
        vertexArray->Bind();
        RenderCommand(window).DrawIndexed(vertexArray);
    }
}