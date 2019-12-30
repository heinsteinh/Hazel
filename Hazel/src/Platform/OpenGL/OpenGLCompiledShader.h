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

        inline unsigned int GetId() const
        {
            return id;
        }

        inline bool IsCompiled() const
        {
            return compiled;
        }

        const std::string &GetInfoLog() const
        {
            return infoLog;
        }

    private:
        void Init(unsigned int type, const std::string &source);
        void Compile(unsigned int type, const std::string &source);
        void RetrieveCompilationStatus();
        void RetrieveInfoLog();
    };
}