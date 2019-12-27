#pragma once

#include <string>
#include <vector>
#include <memory>

#include "glm/glm.hpp"

#include "Hazel/Core/Core.h"
#include "Shader.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"

namespace Hazel
{
    class HAZEL_API Context
    {
    public:
        virtual ~Context() = default;

        virtual void SwapBuffers() const = 0;
        virtual void SetViewport(int width, int height) const = 0;
        virtual void SetClearColor(const glm::vec4 &color) const = 0;
        virtual void Clear() const = 0;
        virtual void DrawIndexed(const std::shared_ptr<VertexArray> &vertexArray) const = 0;
        virtual Shader *CreateShader(const std::string &vertexSource, const std::string &fragmentSource) const = 0;
        virtual VertexArray *CreateVertexArray() const = 0;
        virtual VertexBuffer *CreateVertexBuffer(const std::vector<float> &vertices) const = 0;
        virtual IndexBuffer *CreateIndexBuffer(const std::vector<unsigned int> &indexes) const = 0;
    };
}