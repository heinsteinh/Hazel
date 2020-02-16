#pragma once

#include "OpenGLCompiledShader.h"

namespace Hazel
{
    class OpenGLShaderCompiler
    {
    private:
        unsigned int programId = 0;
        bool linked = false;
        std::string infoLog;
        std::vector<OpenGLCompiledShader> shaders;

    public:
        OpenGLShaderCompiler() = default;

        unsigned int Compile(const std::unordered_map<ShaderType, std::string> &sources);

        inline unsigned int GetProgramId() const
        {
            return programId;
        }

        inline bool HasSucceeded() const
        {
            return linked;
        }

        inline const std::string &GetInfoLog() const
        {
            return infoLog;
        }

    private:
        void CreateProgram(const std::unordered_map<ShaderType, std::string> &sources);
        void Attach(const std::unordered_map<ShaderType, std::string> &sources);
        void Attach(ShaderType type, const std::string &source);
        void RetreiveLinkStatus();
        void RetreiveInfoLog();
        void DisplayInfoLog();
        void Cleanup();
        void DetachShaders();
        void DeleteProgram();
    };
}