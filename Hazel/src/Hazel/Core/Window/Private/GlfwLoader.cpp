#include "GlfwLoader.h"

#include "GLFW/glfw3.h"

#include "Hazel/Core/Logging/Log.h"

namespace Hazel
{
	GlfwLoader::GlfwLoader()
	{
		Log::Debug("GLFW init.");
		glfwSetErrorCallback([](int error, const char *description)
		{
			Log::Error("GLFW error (code {}): {}", error, description);
		});
		if (glfwInit() == GLFW_FALSE)
		{
			throw GlfwException("GLFW cannot be initialized.");
		}
	}

	GlfwLoader::~GlfwLoader()
	{
		Log::Debug("GLFW shutdown.");
		glfwTerminate();
	}
}