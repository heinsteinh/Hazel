#pragma once

#include <string>

namespace Hazel
{
    class OpenGLCompiledShader
    {
    private:
        unsigned int id = 0;
        bool compiled = false;
        std::string infoLog;

    public:
        OpenGLCompiledShader(unsigned int type, const std::string &source);
        ~OpenGLCompiledShader();

        unsigned int GetId() const;
        bool IsCompiled() const;
        const std::string &GetInfoLog() const;

    private:
        void Init(unsigned int type, const std::string &source);
        void Compile(unsigned int type, const std::string &source);
        void CheckCompilationStatus();
        void CheckInfoLog();
    };
}