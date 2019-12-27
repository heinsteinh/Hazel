#include "Renderer.h"

#include "Hazel/Core/Log.h"
#include "Hazel/Renderer/RenderCommand.h"

namespace Hazel
{
    Renderer::Renderer(const Window &window)
        : window(window)
    {
    }

    void Renderer::BeginScene() const
    {
    }

    void Renderer::EndScene() const
    {
    }

    void Renderer::Submit(const std::shared_ptr<VertexArray> &vertexArray) const
    {
        vertexArray->Bind();
        RenderCommand(window).DrawIndexed(vertexArray);
    }
}