#pragma once

#include "Shader.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"

namespace Hazel
{
    class HAZEL_API ObjectFactory
    {
    public:
        virtual ~ObjectFactory() = default;

        virtual Shader *CreateShader(
            const std::string &vertexSource,
            const std::string &fragmentSource
        ) = 0;
        virtual VertexArray *CreateVertexArray() = 0;
        virtual VertexBuffer *CreateVertexBuffer(const std::vector<float> &vertices) = 0;
        virtual IndexBuffer *CreateIndexBuffer(const std::vector<unsigned int> &indexes) = 0;
    };
}