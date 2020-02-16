#pragma once

#include "Hazel/Rendering/Shaders/Shader.h"
#include "Hazel/Rendering/Shaders/ShaderInfo.h"
#include "Hazel/Rendering/Buffers/VertexArray.h"
#include "Hazel/Rendering/Buffers/VertexBuffer.h"
#include "Hazel/Rendering/Buffers/IndexBuffer.h"
#include "Hazel/Rendering/Textures/Texture2D.h"
#include "Hazel/Rendering/Textures/TextureInfo.h"

#include "Hazel/Utils/FileInfo.h"

namespace Hazel
{
    class HAZEL_API ObjectFactory
    {
    public:
        virtual ~ObjectFactory() = default;

        virtual SharedPtr<Shader> CreateShader(const ShaderInfo &info) = 0;
        virtual SharedPtr<VertexArray> CreateVertexArray() = 0;
        virtual SharedPtr<VertexBuffer> CreateVertexBuffer(const std::vector<float> &vertices) = 0;
        virtual SharedPtr<IndexBuffer> CreateIndexBuffer(const std::vector<unsigned int> &indexes) = 0;
        virtual SharedPtr<Texture2D> CreateTexture2D(const TextureInfo &info) = 0;
    };
}