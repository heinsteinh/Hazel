#include "Platform.h"

#include "GLFW/glfw3.h"

namespace Hazel
{
    double Platform::GetTime()
    {
        return glfwGetTime();
    }
}