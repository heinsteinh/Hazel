#pragma once

#include "Hazel/Renderer/Shader.h"
#include "Hazel/Renderer/ShaderDataType.h"

namespace Hazel
{
    class OpenGLShader : public Shader
    {
    private:
        unsigned int rendererId = 0;
        bool built = 0;

    public:
        static unsigned int GetInternalType(const ShaderDataType &type);

        OpenGLShader(const std::string &vertexSource, const std::string &fragmentSource);
        virtual ~OpenGLShader();

        virtual bool IsBuilt() const override;

        virtual void Bind() const override;
        virtual void UnBind() const override;

    private:
        void Init(const std::string &vertexSource, const std::string &fragmentSource);
    };
}