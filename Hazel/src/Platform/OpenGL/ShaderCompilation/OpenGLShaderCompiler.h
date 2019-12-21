#pragma once

#include "OpenGLProgramData.h"

namespace Hazel
{
    class OpenGLShaderCompiler
    {
    private:
        unsigned int rendererId = 0;
        OpenGLShaderData vertexData;
        OpenGLShaderData fragmentData;
        OpenGLProgramData program;

    public:
        OpenGLShaderCompiler();

        bool Compile(const std::string &vertexSource, const std::string &fragmentSource);
        unsigned int GetRendererId() const;

    private:
        bool CompileSource(const std::string &vertexSource, const std::string &fragmentSource);
        void DisplayShaderCompilationLog();
        bool CreateProgramAndLink();
        void DisplayProgramLinkLog();
    };
}