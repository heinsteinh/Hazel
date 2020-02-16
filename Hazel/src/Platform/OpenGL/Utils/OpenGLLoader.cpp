#include "OpenGLLoader.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "OpenGLDebugger.h"

namespace Hazel
{
    OpenGLLoader::OpenGLLoader()
    {
        Init();
    }

    void OpenGLLoader::Init()
    {
        LoadGlad();
        DisplayOpenGLInfo();
        SetupConfiguration();
#ifdef _DEBUG
        SetupDebugging();
#endif
    }

    void OpenGLLoader::LoadGlad()
    {
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            CoreCritical("Glad cannot be initialized.");
            exit(-1);
        }
    }

    void OpenGLLoader::DisplayOpenGLInfo()
    {
        CoreInfo("OpenGL version: {}", glGetString(GL_VERSION));
        CoreInfo("OpenGL vendor: {}", glGetString(GL_VENDOR));
        CoreInfo("OpenGL renderer: {}", glGetString(GL_RENDERER));
    }

    void OpenGLLoader::SetupConfiguration()
    {
        glEnable(GL_MULTISAMPLE);
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }

    void OpenGLLoader::SetupDebugging()
    {
        static OpenGLDebugger debugger;
    }
}