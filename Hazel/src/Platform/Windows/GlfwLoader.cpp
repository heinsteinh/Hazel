#include "GlfwLoader.h"

#include "GLFW/glfw3.h"

#include "Hazel/Core/Logger.h"

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
        glfwInit()
            ? CoreDebug("GLFW initialized.")
            : CoreError("GLFW cannot be initialized.");
    }

    GlfwLoader::~GlfwLoader()
    {
        CoreDebug("GLFW terminate.");
        glfwTerminate();
        CoreDebug("GLFW terminated.");
    }
}