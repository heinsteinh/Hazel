#pragma once

#include "Hazel/Renderer/ShaderDataType.h"

namespace Hazel
{
    class OpenGLDataType
    {
    public:
        static unsigned int GetInternalType(const ShaderDataType &type);

        OpenGLDataType() = delete;
    };
}