#pragma once

#include "glm/glm.hpp"

#include "ObjectFactory.h"

namespace Hazel
{
    class HAZEL_API Context
    {
    public:
        virtual ~Context() = default;

        virtual ObjectFactory &GetFactory() = 0;
        virtual void SwapBuffers() = 0;
        virtual void SetViewport(int width, int height) = 0;
        virtual void SetClearColor(const glm::vec4 &color) = 0;
        virtual void Clear() = 0;
        virtual void DrawIndexed(const SharedPtr<VertexArray> &vertexArray) = 0;
    };
}