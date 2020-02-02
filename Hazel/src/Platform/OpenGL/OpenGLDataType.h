#pragma once

#include "Hazel/Rendering/ShaderDataType.h"

namespace Hazel
{
    class OpenGLDataType
    {
    public:
        static unsigned int GetShaderDataType(ShaderDataType type);
        static unsigned int GetShaderType(const std::string &name);

        OpenGLDataType() = delete;
    };
}