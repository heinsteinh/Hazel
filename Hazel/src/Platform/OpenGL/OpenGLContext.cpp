#include "OpenGLContext.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "OpenGLDebugger.h"

namespace Hazel
{
    OpenGLContext::OpenGLContext(GLFWwindow *window)
        : window(window),
        factory()
    {
        Init();
    }

    ObjectFactory &OpenGLContext::GetFactory()
    {
        return factory;
    }

    void OpenGLContext::MakeCurrent()
    {
        glfwMakeContextCurrent(window);
    }

    void OpenGLContext::SwapBuffers()
    {
        glfwSwapBuffers(window);
    }

    void OpenGLContext::SetViewport(int width, int height)
    {
        glViewport(0, 0, width, height);
    }

    void OpenGLContext::SetClearColor(const glm::vec4 &color)
    {
        glClearColor(color.r, color.g, color.b, color.a);
    }

    void OpenGLContext::Clear()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void OpenGLContext::DrawIndexed(const SharedPtr<VertexArray> &vertexArray)
    {
        glDrawElements(
            GL_TRIANGLES,
            (int)vertexArray->GetIndexBuffer()->GetSize(),
            GL_UNSIGNED_INT,
            nullptr);
    }

    void OpenGLContext::Init()
    {
        MakeCurrent();
        LoadGlad();
        DisplayOpenGLInfo();
        SetupParameters();
    }

    void OpenGLContext::LoadGlad()
    {
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            CoreCritical("Glad cannot be initialized.");
            exit(-1);
        }
    }

    void OpenGLContext::DisplayOpenGLInfo()
    {
        CoreInfo("OpenGL version: {}", glGetString(GL_VERSION));
        CoreInfo("OpenGL vendor: {}", glGetString(GL_VENDOR));
        CoreInfo("OpenGL renderer: {}", glGetString(GL_RENDERER));
    }

    void OpenGLContext::SetupParameters()
    {
        static OpenGLDebugger debugger;
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }
}