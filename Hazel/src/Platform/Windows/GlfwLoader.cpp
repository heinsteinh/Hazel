#include "GlfwLoader.h"

#include "GLFW/glfw3.h"

#include "Hazel/Core/Log.h"

namespace Hazel
{
    void GlfwLoader::OnError(int error, const char *description)
    {
        CoreError("GLFW Error {}: {}", error, description);
    }

    GlfwLoader::GlfwLoader()
    {
        Init();
    }

    GlfwLoader::~GlfwLoader()
    {
        Shutdown();
    }

    void GlfwLoader::Init()
    {
        CoreDebug("GLFW initialization.");
        SetupDebugging();
        InitGlfw();
        SetupConfiguration();
        CoreDebug("GLFW initialized.");
    }

    void GlfwLoader::SetupDebugging()
    {
        glfwSetErrorCallback(&OnError);
    }

    void GlfwLoader::InitGlfw()
    {
        if (!glfwInit())
        {
            CoreCritical("GLFW cannot be initialized.");
            exit(-1);
        }
    }

    void GlfwLoader::SetupConfiguration()
    {
        glfwWindowHint(GLFW_SAMPLES, 4);
    }

    void GlfwLoader::Shutdown()
    {
        CoreDebug("GLFW terminate.");
        glfwTerminate();
        CoreDebug("GLFW terminated.");
    }
}