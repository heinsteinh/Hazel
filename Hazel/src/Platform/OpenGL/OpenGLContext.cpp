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
            CoreError("Glad cannot be initialized.");
        }
    }
}