#pragma once

#include "OpenGLShaderData.h"

namespace Hazel
{
    class OpenGLProgramData
    {
    private:
        unsigned int id = 0;
        bool linked = false;
        std::string infoLog;

    public:
        OpenGLProgramData();

        bool Link(const OpenGLShaderData &vertexData, const OpenGLShaderData &fragmentData);
        unsigned int GetId() const;
        bool IsLinked() const;
        const std::string &GetInfoLog() const;

    private:
        void CreateAndLink(const OpenGLShaderData &vertexData, const OpenGLShaderData &fragmentData);
        void GetLinkResult(const OpenGLShaderData &vertexData, const OpenGLShaderData &fragmentData);
        void Cleanup(const OpenGLShaderData &vertexData, const OpenGLShaderData &fragmentData);
    };
}