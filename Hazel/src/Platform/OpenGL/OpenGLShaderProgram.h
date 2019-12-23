#pragma once

#include <unordered_set>

#include "OpenGLCompiledShader.h"

namespace Hazel
{
    class OpenGLShaderProgram
    {
    private:
        unsigned int id;
        bool linked = false;
        std::string infoLog;
        std::unordered_set<unsigned int> shaders;

    public:
        OpenGLShaderProgram();
        ~OpenGLShaderProgram();

        unsigned int GetId() const;
        bool IsLinked() const;
        const std::string &GetInfoLog() const;
        void Attach(const OpenGLCompiledShader &shader);
        void Detach(const OpenGLCompiledShader &shader);
        void Link();

    private:
        void CheckLinkStatus();
        void CheckInfoLog();
        void Cleanup();
    };
}