#pragma once

#include <unordered_set>

#include "OpenGLCompiledShader.h"

namespace Hazel
{
    class OpenGLShaderLinker
    {
    private:
        unsigned int programId = 0;
        bool linked = false;
        std::string infoLog;
        std::unordered_set<unsigned int> shaders;

    public:
        OpenGLShaderLinker() = default;
        ~OpenGLShaderLinker() = default;

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

        void Attach(const OpenGLCompiledShader &shader);
        void Detach(const OpenGLCompiledShader &shader);
        unsigned int CreateProgram();

    private:
        void AttachAndLink();
        void RetreiveLinkStatus();
        void RetreiveInfoLog();
        void DisplayInfoLog();
        void Cleanup();
    };
}