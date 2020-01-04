#include "OpenGLContext.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "OpenGLDebugger.h"

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