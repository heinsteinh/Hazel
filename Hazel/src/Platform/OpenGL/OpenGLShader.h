#pragma once

#include "Hazel/Renderer/Shader.h"
#include "OpenGLShaderProgram.h"

namespace Hazel
{
    class OpenGLShader : public Shader
    {
    private:
        OpenGLShaderProgram program;
        OpenGLCompiledShader vertexShader;
        OpenGLCompiledShader fragmentShader;

    public:
        OpenGLShader(const std::string &vertexSource, const std::string &fragmentSource);
        virtual ~OpenGLShader();

        virtual bool IsExecutable() const override;
        virtual void UploadUniformMat4(const std::string &name, const glm::mat4 &uniform) override;
        virtual void Bind() const override;
        virtual void UnBind() const override;

    private:
        void Init();
        void DisplayCompilationLog(const std::string &name, const OpenGLCompiledShader &shader);
        void CreateProgram();
        void DisplayLinkLog();
    };
}