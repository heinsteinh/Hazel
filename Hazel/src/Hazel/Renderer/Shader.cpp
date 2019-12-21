#include "Shader.h"

#include <unordered_map>

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLShader.h"

namespace Hazel
{
    Shader *Shader::Create(const std::string &vertexSource, const std::string &fragmentSource)
    {
        switch (Renderer::GetApi())
        {
        case Renderer::Api::OpenGL:
            return new OpenGLShader(vertexSource, fragmentSource);
        }
        return nullptr;
    }
}