#include "Time.h"

#include "GLFW/glfw3.h"

namespace Hazel
{
    float Time::GetTime()
    {
        return static_cast<float>(glfwGetTime());
    }
}