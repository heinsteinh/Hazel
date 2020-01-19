#pragma once

#include "Hazel/Rendering/ObjectFactory.h"

namespace Hazel
{
    class OpenGLObjectFactory : public ObjectFactory
    {
    public:
        OpenGLObjectFactory() = default;
        virtual ~OpenGLObjectFactory() = default;

        virtual SharedPtr<Shader> CreateShader(
            const std::string &name,
            const std::string &vertexSource,
            const std::string &fragmentSource
        ) override;
        virtual SharedPtr<Shader> CreateShader(
            const std::string &filename
        ) override;
        virtual SharedPtr<Shader> CreateShader(
            const std::string &name,
            const std::string &filename
        ) override;
        virtual SharedPtr<VertexArray> CreateVertexArray() override;
        virtual SharedPtr<VertexBuffer> CreateVertexBuffer(const std::vector<float> &vertices) override;
        virtual SharedPtr<IndexBuffer> CreateIndexBuffer(const std::vector<unsigned int> &indexes) override;
        virtual SharedPtr<Texture2D> CreateTexture2D(int width, int height) override;
        virtual SharedPtr<Texture2D> CreateTexture2D(const std::string &filename) override;
    };
}