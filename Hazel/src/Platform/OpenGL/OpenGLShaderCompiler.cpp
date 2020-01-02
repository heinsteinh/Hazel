#include "OpenGLShaderCompiler.h"

#include "glad/glad.h"

#include "OpenGLShaderParser.h"
#include "OpenGLShaderLinker.h"

namespace Hazel
{
    unsigned int OpenGLShaderCompiler::Compile(const std::string &filename)
    {
        OpenGLShaderParser parser;
        if (!parser.Parse(filename))
        {
            CoreError("Parsing of shader file {} failed.", filename);
            return programId = 0;
        }
        CoreInfo("{} shader(s) parsed from {}.", parser.GetSources().size(), filename);
        return programId = OpenGLShaderLinker().CreateProgram(parser.GetSources());
    }

    unsigned int OpenGLShaderCompiler::Compile(const std::string &vertexSource, const std::string &fragmentSource)
    {
        return programId = OpenGLShaderLinker().CreateProgram({
            {GL_VERTEX_SHADER, vertexSource},
            {GL_FRAGMENT_SHADER, fragmentSource}});
    }
}