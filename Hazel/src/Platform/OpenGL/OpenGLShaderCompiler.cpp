#include "OpenGLShaderCompiler.h"

#include "glad/glad.h"

#include "OpenGLShaderParser.h"
#include "OpenGLShaderLinker.h"

namespace Hazel
{
    unsigned int OpenGLShaderCompiler::Compile(const std::string &filename)
    {
        OpenGLShaderParser parser;
        parser.Parse(filename);
        if (parser.HasFailed())
        {
            CoreError("Shaders compilation from {} failed.", filename);
            return programId = 0;
        }
        CoreInfo("Shader compilation from {} succeeded.", filename);
        return programId = Compile(parser.GetSources());
    }

    unsigned int OpenGLShaderCompiler::Compile(const std::string &vertexSource, const std::string &fragmentSource)
    {
        return Compile({
            {GL_VERTEX_SHADER, vertexSource},
            {GL_FRAGMENT_SHADER, fragmentSource}});
    }

    unsigned int OpenGLShaderCompiler::Compile(const std::unordered_map<unsigned int, std::string> &sources)
    {
        programId = 0;
        std::vector<OpenGLCompiledShader> shaders;
        shaders.reserve(sources.size());
        OpenGLShaderLinker linker;
        for (const auto &[type, source] : sources)
        {
            auto &shader = shaders.emplace_back(type, source);
            if (shader.IsCompiled())
            {
                linker.Attach(shader);
            }
        }
        return programId = linker.CreateProgram();
    }
}