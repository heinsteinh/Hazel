#include "OpenGLContext.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "Hazel/Core/Log.h"
#include "OpenGLShader.h"
#include "OpenGLVertexArray.h"
#include "OpenGLVertexBuffer.h"
#include "OpenGLIndexBuffer.h"

namespace Hazel
{
    OpenGLContext::OpenGLContext(GLFWwindow *window)
        : window(window)
    {
        Init();
    }

    void OpenGLContext::SwapBuffers() const
    {
        glfwSwapBuffers(window);
    }

    void OpenGLContext::SetViewport(int width, int height) const
    {
        glfwMakeContextCurrent(window);
        glViewport(0, 0, width, height);
    }

    void OpenGLContext::SetClearColor(const glm::vec4 &color) const
    {
        glfwMakeContextCurrent(window);
        glClearColor(color.r, color.g, color.b, color.a);
    }

    void OpenGLContext::Clear() const
    {
        glfwMakeContextCurrent(window);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void OpenGLContext::DrawIndexed(const std::shared_ptr<VertexArray> &vertexArray) const
    {
        glfwMakeContextCurrent(window);
        glDrawElements(
            GL_TRIANGLES,
            (int)vertexArray->GetIndexBuffer()->GetSize(),
            GL_UNSIGNED_INT,
            nullptr);
    }

    Shader *OpenGLContext::CreateShader(const std::string &vertexSource, const std::string &fragmentSource) const
    {
        glfwMakeContextCurrent(window);
        return new OpenGLShader(vertexSource, fragmentSource);
    }

    VertexArray *OpenGLContext::CreateVertexArray() const
    {
        glfwMakeContextCurrent(window);
        return new OpenGLVertexArray();
    }

    VertexBuffer *OpenGLContext::CreateVertexBuffer(const std::vector<float> &vertices) const
    {
        glfwMakeContextCurrent(window);
        return new OpenGLVertexBuffer(vertices);
    }

    IndexBuffer *OpenGLContext::CreateIndexBuffer(const std::vector<unsigned int> &indexes) const
    {
        glfwMakeContextCurrent(window);
        return new OpenGLIndexBuffer(indexes);
    }

    void OpenGLContext::Init()
    {
        glfwMakeContextCurrent(window);
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            CoreCritical("Glad cannot be initialized.");
        }
        CoreInfo("OpenGL version: {}", glGetString(GL_VERSION));
        CoreInfo("OpenGL vendor: {}", glGetString(GL_VENDOR));
        CoreInfo("OpenGL renderer: {}", glGetString(GL_RENDERER));
    }
}