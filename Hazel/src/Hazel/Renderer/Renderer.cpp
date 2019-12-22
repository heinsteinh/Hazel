#include "Renderer.h"

#include <unordered_map>
#include <memory>

#include "Hazel/Core/Logger.h"
#include "Hazel/Utils/UniquePtrMap.h"
#include "Platform/OpenGL/OpenGLRenderer.h"

namespace Hazel
{
    static UniquePtrMap<Renderer::Api, Renderer> renderers = {
        {Renderer::Api::OpenGL, new OpenGLRenderer()}
    };

    Renderer::Api Renderer::api = Renderer::Api::OpenGL;
    Renderer *Renderer::activeRenderer = &renderers[Renderer::api];

    void Renderer::SetApi(Api api)
    {
        if (renderers.Contains(api))
        {
            Renderer::api = api;
            activeRenderer = &renderers[api];
            CoreInfo("Rendering API set to {}", api);
        }
        else
        {
            CoreError("Unknown rendering API: {}", api);
        }
    }

    Renderer::Api Renderer::GetApi()
    {
        return api;
    }

    Renderer &Renderer::Get()
    {
        return *activeRenderer;
    }
}