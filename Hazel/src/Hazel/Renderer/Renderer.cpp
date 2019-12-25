#include "Renderer.h"

#include "Hazel/Core/Log.h"
#include "Hazel/Renderer/RenderCommand.h"
#include "Hazel/Utils/UniquePtrMap.h"
#include "Platform/OpenGL/OpenGLRenderApi.h"

namespace Hazel
{
    static UniquePtrMap<Renderer::Api, RenderApi> apiMap = {
        {Renderer::Api::OpenGL, new OpenGLRenderApi()}
    };

    Renderer::Api Renderer::api = Renderer::Api::OpenGL;
    RenderApi *Renderer::renderApi = &apiMap[api];

    void Renderer::SetApi(Api api)
    {
        if (apiMap.Contains(api))
        {
            Renderer::api = api;
            renderApi = &apiMap[api];
            CoreInfo("Rendering API set to {}.", api);
        }
        else
        {
            CoreError("Unknown rendering API: {}.", api);
        }
    }

    Renderer::Api Renderer::GetApi()
    {
        return api;
    }

    RenderApi &Renderer::GetRenderApi()
    {
        return *renderApi;
    }

    void Renderer::BeginScene()
    {
    }

    void Renderer::EndScene()
    {
    }

    void Renderer::Submit(const std::shared_ptr<VertexArray> &vertexArray)
    {
        vertexArray->Bind();
        RenderCommand::DrawIndexed(vertexArray);
    }
}