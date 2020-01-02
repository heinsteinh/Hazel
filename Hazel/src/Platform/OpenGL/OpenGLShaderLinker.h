#pragma once

#include "OpenGLCompiledShader.h"

namespace Hazel
{
    class OpenGLShaderLinker
    {
    private:
        unsigned int programId = 0;
        bool linked = false;
        std::string infoLog;
        std::vector<OpenGLCompiledShader> shaders;

    public:
        OpenGLShaderLinker() = default;

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

        unsigned int CreateProgram(const std::unordered_map<unsigned int, std::string> &sources);

    private:
        void AttachAndLink(const std::unordered_map<unsigned int, std::string> &sources);
        void Attach(unsigned int type, const std::string &source);
        void RetreiveLinkStatus();
        void RetreiveInfoLog();
        void DisplayInfoLog();
        void Cleanup();
    };
}