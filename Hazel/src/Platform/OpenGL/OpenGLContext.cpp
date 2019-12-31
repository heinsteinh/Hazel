#include "OpenGLContext.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace Hazel
{
    OpenGLContext::OpenGLContext(GLFWwindow *window)
        : window(window),
        factory(*this)
    {
        Init();
    }

    ObjectFactory &OpenGLContext::GetFactory()
    {
        return factory;
    }

    void OpenGLContext::MakeCurrent()
    {
        static Context *current = nullptr;
        if (current != this)
        {
            glfwMakeContextCurrent(window);
            current = this;
        }
    }

    void OpenGLContext::SwapBuffers()
    {
        MakeCurrent();
        glfwSwapBuffers(window);
    }

    void OpenGLContext::SetViewport(int width, int height)
    {
        MakeCurrent();
        glViewport(0, 0, width, height);
    }

    void OpenGLContext::SetClearColor(const glm::vec4 &color)
    {
        MakeCurrent();
        glClearColor(color.r, color.g, color.b, color.a);
    }

    void OpenGLContext::Clear()
    {
        MakeCurrent();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void OpenGLContext::DrawIndexed(const SharedPtr<VertexArray> &vertexArray)
    {
        MakeCurrent();
        glDrawElements(
            GL_TRIANGLES,
            (int)vertexArray->GetIndexBuffer()->GetSize(),
            GL_UNSIGNED_INT,
            nullptr);
    }

    void OpenGLContext::Init()
    {
        MakeCurrent();
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            CoreCritical("Glad cannot be initialized.");
        }
        CoreInfo("OpenGL version: {}", glGetString(GL_VERSION));
        CoreInfo("OpenGL vendor: {}", glGetString(GL_VENDOR));
        CoreInfo("OpenGL renderer: {}", glGetString(GL_RENDERER));
    }
}