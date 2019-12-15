#include "Shader.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "Hazel/Core/Logger.h"

namespace Hazel
{
    Shader::Shader(const std::string &vertexSource, const std::string &fragmentSource)
    {
        // Create an empty vertex shader handle
        unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);

        // Send the vertex shader source code to GL
        // Note that std::string's .c_str is NULL character terminated.
        const char *source = vertexSource.c_str();
        glShaderSource(vertexShader, 1, &source, 0);

        // Compile the vertex shader
        glCompileShader(vertexShader);

        int isCompiled = 0;
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &isCompiled);
        if (isCompiled == GL_FALSE)
        {
            int maxLength = 0;
            glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &maxLength);

            // The maxLength includes the NULL character
            std::vector<char> infoLog(maxLength);
            glGetShaderInfoLog(vertexShader, maxLength, &maxLength, &infoLog[0]);

            // We don't need the shader anymore.
            glDeleteShader(vertexShader);

            // Use the infoLog as you see fit.
            CoreError("Vertex compilation failure: {}", infoLog.data());

            // In this simple program, we'll just leave
            return;
        }

        // Create an empty fragment shader handle
        unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

        // Send the fragment shader source code to GL
        // Note that std::string's .c_str is NULL character terminated.
        source = fragmentSource.c_str();
        glShaderSource(fragmentShader, 1, &source, 0);

        // Compile the fragment shader
        glCompileShader(fragmentShader);

        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &isCompiled);
        if (isCompiled == GL_FALSE)
        {
            int maxLength = 0;
            glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &maxLength);

            // The maxLength includes the NULL character
            std::vector<char> infoLog(maxLength);
            glGetShaderInfoLog(fragmentShader, maxLength, &maxLength, &infoLog[0]);

            // We don't need the shader anymore.
            glDeleteShader(fragmentShader);
            // Either of them. Don't leak shaders.
            glDeleteShader(vertexShader);

            // Use the infoLog as you see fit.
            CoreError("Fragment compilation failure: {}", infoLog.data());

            // In this simple program, we'll just leave
            return;
        }

        // Vertex and fragment shaders are successfully compiled.
        // Now time to link them together into a program.
        // Get a program object.
        rendererId = glCreateProgram();

        // Attach our shaders to our program
        glAttachShader(rendererId, vertexShader);
        glAttachShader(rendererId, fragmentShader);

        // Link our program
        glLinkProgram(rendererId);

        // Note the different functions here: glGetProgram* instead of glGetShader*.
        int isLinked = 0;
        glGetProgramiv(rendererId, GL_LINK_STATUS, &isLinked);
        if (isLinked == GL_FALSE)
        {
            int maxLength = 0;
            glGetProgramiv(rendererId, GL_INFO_LOG_LENGTH, &maxLength);

            // The maxLength includes the NULL character
            std::vector<char> infoLog(maxLength);
            glGetProgramInfoLog(rendererId, maxLength, &maxLength, &infoLog[0]);

            // We don't need the program anymore.
            glDeleteProgram(rendererId);
            // Don't leak shaders either.
            glDeleteShader(vertexShader);
            glDeleteShader(fragmentShader);

            // Use the infoLog as you see fit.
            CoreError("Shader link failure: {}", infoLog.data());

            // In this simple program, we'll just leave
            return;
        }

        // Always detach shaders after a successful link.
        glDetachShader(rendererId, vertexShader);
        glDetachShader(rendererId, fragmentShader);
    }

    Shader::~Shader()
    {
        glDeleteProgram(rendererId);
    }

    void Shader::Bind() const
    {
        glUseProgram(rendererId);
    }

    void Shader::UnBind() const
    {
        glUseProgram(0);
    }
}