#include "OpenGLContext.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "Hazel/Core/Logger.h"

namespace Hazel
{
    OpenGLContext::OpenGLContext(GLFWwindow *window)
        : window(window)
    {
        Init();
    }

    void Hazel::OpenGLContext::SwapBuffers()
    {
        glfwSwapBuffers(window);
    }

    void OpenGLContext::OnUpdate()
    {
        SwapBuffers();
    }

    void Hazel::OpenGLContext::Init()
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