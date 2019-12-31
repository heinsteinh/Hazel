#pragma once

#include "Hazel/Renderer/Context.h"

namespace Hazel
{
    class OpenGLObjectFactory : public ObjectFactory
    {
    private:
        Context &context;

    public:
        OpenGLObjectFactory(Context &context);
        virtual ~OpenGLObjectFactory() = default;

        virtual SharedPtr<Shader> CreateShader(const std::string &vertexSource, const std::string &fragmentSource) override;
        virtual SharedPtr<VertexArray> CreateVertexArray() override;
        virtual SharedPtr<VertexBuffer> CreateVertexBuffer(const std::vector<float> &vertices) override;
        virtual SharedPtr<IndexBuffer> CreateIndexBuffer(const std::vector<unsigned int> &indexes) override;
        virtual SharedPtr<Texture2D> CreateTexture2D(const std::string &filename) override;
    };
}