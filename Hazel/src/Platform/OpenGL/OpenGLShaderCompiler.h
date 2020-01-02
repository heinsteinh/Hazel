#pragma once

namespace Hazel
{
    class OpenGLShaderCompiler
    {
    private:
        unsigned int programId = 0;

    public:
        OpenGLShaderCompiler() = default;

        unsigned int Compile(const std::string &filename);
        unsigned int Compile(const std::string &vertexSource, const std::string &fragmentSource);

        inline bool HasSucceeded() const
        {
            return programId != 0;
        }

        unsigned int GetProgramId() const
        {
            return programId;
        }
    };
}