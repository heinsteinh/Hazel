#pragma once

#include "glm/glm.hpp"

#include "Hazel/Core/Core.h"
#include "Hazel/Renderer/ObjectFactory.h"

namespace Hazel
{
    class HAZEL_API RenderApi
    {
    public:
        virtual ~RenderApi() = default;

        virtual ObjectFactory &GetObjectFactory() = 0;
        virtual void SetClearColor(const glm::vec4 &color) = 0;
        virtual void Clear() = 0;
        virtual void DrawIndexed(const std::shared_ptr<VertexArray> &vertexArray) = 0;
    };
}