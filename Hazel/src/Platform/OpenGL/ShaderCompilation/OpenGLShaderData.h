#pragma once

#include <string>

namespace Hazel
{
    class OpenGLShaderData
    {
    private:
        unsigned int type = 0;
        unsigned int id = 0;
        bool compiled = false;
        std::string infoLog;

    public:
        OpenGLShaderData(unsigned int type);
        ~OpenGLShaderData();

        bool Compile(const std::string &source);
        unsigned int GetId() const;
        bool IsCompiled() const;
        const std::string &GetInfoLog() const;

    private:
        void CompileSource(const std::string &source);
        void GetCompilationResult();
    };
}