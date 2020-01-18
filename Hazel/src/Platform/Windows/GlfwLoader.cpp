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
        CoreDebug("GLFW initialization.");
        glfwSetErrorCallback(&OnError);
        if (!glfwInit())
        {
            CoreCritical("GLFW cannot be initialized.");
            exit(-1);
        }
        CoreDebug("GLFW initialized.");
    }

    GlfwLoader::~GlfwLoader()
    {
        CoreDebug("GLFW terminate.");
        glfwTerminate();
        CoreDebug("GLFW terminated.");
    }
}