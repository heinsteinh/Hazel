#pragma once

#include "Shader.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Texture2D.h"

namespace Hazel
{
    class HAZEL_API ObjectFactory
    {
    public:
        virtual ~ObjectFactory() = default;

        virtual SharedPtr<Shader> CreateShader(
            const std::string &name,
            const std::string &vertexSource,
            const std::string &fragmentSource
        ) = 0;
        virtual SharedPtr<Shader> CreateShader(
            const std::string &filename
        ) = 0;
        virtual SharedPtr<Shader> CreateShader(
            const std::string &name,
            const std::string &filename
        ) = 0;
        virtual SharedPtr<VertexArray> CreateVertexArray() = 0;
        virtual SharedPtr<VertexBuffer> CreateVertexBuffer(const std::vector<float> &vertices) = 0;
        virtual SharedPtr<IndexBuffer> CreateIndexBuffer(const std::vector<unsigned int> &indexes) = 0;
        virtual SharedPtr<Texture2D> CreateTexture2D(int width, int height) = 0;
        virtual SharedPtr<Texture2D> CreateTexture2D(const std::string &filename) = 0;
    };
}