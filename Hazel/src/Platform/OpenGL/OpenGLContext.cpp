#include "OpenGLContext.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "OpenGLLoader.h"

namespace Hazel
{
    OpenGLContext::OpenGLContext(GLFWwindow *window)
        : window(window),
        drawer(window)
    {
        Init();
    }

    ObjectFactory &OpenGLContext::GetFactory()
    {
        return factory;
    }

    Drawer &OpenGLContext::GetDrawer()
    {
        return drawer;
    }

    void OpenGLContext::MakeCurrent()
    {
        glfwMakeContextCurrent(window);
    }

    void OpenGLContext::Init()
    {
        MakeCurrent();
        LoadOpenGL();
    }

    void OpenGLContext::LoadOpenGL()
    {
        static OpenGLLoader loader;
    }
}