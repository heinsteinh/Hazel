#pragma once

#include "Hazel/Rendering/Drawing/ObjectFactory.h"

namespace Hazel
{
    class OpenGLObjectFactory : public ObjectFactory
    {
    public:
        OpenGLObjectFactory() = default;
        virtual ~OpenGLObjectFactory() = default;

        virtual SharedPtr<Shader> CreateShader(const ShaderInfo &info) override;
        virtual SharedPtr<VertexArray> CreateVertexArray() override;
        virtual SharedPtr<VertexBuffer> CreateVertexBuffer(const std::vector<float> &vertices) override;
        virtual SharedPtr<IndexBuffer> CreateIndexBuffer(const std::vector<unsigned int> &indexes) override;
        virtual SharedPtr<Texture2D> CreateTexture2D(const TextureInfo &info) override;
    };
}