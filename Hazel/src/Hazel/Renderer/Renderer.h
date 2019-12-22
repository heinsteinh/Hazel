#pragma once

#include <vector>

#include "Hazel/Core/Core.h"
#include "Hazel/Renderer/VertexArray.h"
#include "Hazel/Renderer/RenderApi.h"

namespace Hazel
{
    class HAZEL_API Renderer
    {
    public:
        enum class Api
        {
            OpenGL
        };

    private:
        static Api api;
        static RenderApi *renderApi;

    public:
        static void SetApi(Api api);
        static Api GetApi();
        static RenderApi &GetRenderApi();

        static void BeginScene();
        static void EndScene();
        static void Submit(const std::shared_ptr<VertexArray> &vertexArray);

        static inline Context *CreateContext(const Window &window)
        {
            return Renderer::GetRenderApi().GetObjectFactory().CreateContext(window);
        }

        static inline Shader *CreateShader(const std::string &vertexSource, const std::string &fragmentSource)
        {
            return Renderer::GetRenderApi().GetObjectFactory().CreateShader(vertexSource, fragmentSource);
        }

        static inline VertexArray *CreateVertexArray()
        {
            return Renderer::GetRenderApi().GetObjectFactory().CreateVertexArray();
        }

        static inline VertexBuffer *CreateVertexBuffer(const std::vector<float> &vertices)
        {
            return Renderer::GetRenderApi().GetObjectFactory().CreateVertexBuffer(vertices);
        }

        static inline IndexBuffer *CreateIndexBuffer(const std::vector<unsigned int> &indexes)
        {
            return Renderer::GetRenderApi().GetObjectFactory().CreateIndexBuffer(indexes);
        }

        Renderer() = delete;
    };
}