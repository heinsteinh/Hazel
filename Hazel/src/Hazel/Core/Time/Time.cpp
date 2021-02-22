#include "Time.h"

#include "GLFW/glfw3.h"

namespace Hazel
{
	double Time::GetTime()
	{
		return glfwGetTime();
	}
}