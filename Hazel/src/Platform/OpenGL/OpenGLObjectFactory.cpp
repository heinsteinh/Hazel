#include "OpenGLObjectFactory.h"

#include "GLFW/glfw3.h"

#include "OpenGLShader.h"
#include "OpenGLVertexArray.h"
#include "OpenGLVertexBuffer.h"
#include "OpenGLIndexBuffer.h"

namespace Hazel
{
    OpenGLObjectFactory::OpenGLObjectFactory(GLFWwindow *window)
        : window(window)
    {
    }

    Shader *OpenGLObjectFactory::CreateShader(
        const std::string &vertexSource,
        const std::string &fragmentSource)
    {
        glfwMakeContextCurrent(window);
        return new OpenGLShader(vertexSource, fragmentSource);
    }

    VertexArray *OpenGLObjectFactory::CreateVertexArray()
    {
        glfwMakeContextCurrent(window);
        return new OpenGLVertexArray();
    }

    VertexBuffer *OpenGLObjectFactory::CreateVertexBuffer(const std::vector<float> &vertices)
    {
        glfwMakeContextCurrent(window);
        return new OpenGLVertexBuffer(vertices);
    }

    IndexBuffer *OpenGLObjectFactory::CreateIndexBuffer(const std::vector<unsigned int> &indexes)
    {
        glfwMakeContextCurrent(window);
        return new OpenGLIndexBuffer(indexes);
    }
}