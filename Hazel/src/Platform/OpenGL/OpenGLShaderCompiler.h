#pragma once

#include "OpenGLShaderProgram.h"

namespace Hazel
{
    class OpenGLShaderCompiler
    {
    private:
        OpenGLShaderProgram program;
        OpenGLCompiledShader vertexShader;
        OpenGLCompiledShader fragmentShader;

    public:
        OpenGLShaderCompiler(const std::string &vertexSource, const std::string &fragmentSource);

        inline bool HasSucceeded() const
        {
            return program.IsLinked() && vertexShader.IsCompiled() && fragmentShader.IsCompiled();
        }

        unsigned int GetProgramId() const
        {
            return program.GetId();
        }

    private:
        void Init();
        void DisplayCompilationLog(const std::string &name, const OpenGLCompiledShader &shader);
        void CreateProgram();
        void DisplayLinkLog();
    };
}