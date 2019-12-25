#pragma once

#include "Hazel/Renderer/RenderApi.h"

namespace Hazel
{
    class OpenGLRenderApi : public RenderApi
    {
    public:
        virtual ~OpenGLRenderApi() = default;

        virtual ObjectFactory &GetObjectFactory() override;
        virtual void SetClearColor(const glm::vec4 &color) override;
        virtual void Clear() override;
        virtual void DrawIndexed(const std::shared_ptr<VertexArray> &vertexArray) override;
    };
}