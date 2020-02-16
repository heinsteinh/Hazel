#pragma once

#include "Hazel/Rendering/Shaders/ShaderType.h"

namespace Hazel
{
    class OpenGLCompiledShader
    {
    private:
        unsigned int id = 0;
        ShaderType type;
        bool compiled = false;
        std::string infoLog;

    public:
        OpenGLCompiledShader(ShaderType type, const std::string &source);
        OpenGLCompiledShader(const OpenGLCompiledShader &other) = delete;
        OpenGLCompiledShader(OpenGLCompiledShader &&other);
        ~OpenGLCompiledShader();

        OpenGLCompiledShader &operator=(const OpenGLCompiledShader &other) = delete;
        OpenGLCompiledShader &operator=(OpenGLCompiledShader &&other);

        inline unsigned int GetId() const
        {
            return id;
        }

        inline bool IsCompiled() const
        {
            return compiled;
        }

        inline const std::string &GetInfoLog() const
        {
            return infoLog;
        }

    private:
        void Init(const std::string &source);
        void Compile(const std::string &source);
        void RetrieveCompilationStatus();
        void RetrieveInfoLog();
        void DisplayInfoLog();
    };
}