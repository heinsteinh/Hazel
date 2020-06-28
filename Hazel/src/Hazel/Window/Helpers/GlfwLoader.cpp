#include "GlfwLoader.h"

#include "GLFW/glfw3.h"

namespace Hazel
{
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
		Log::Debug("GLFW initialization.");
		SetupErrorCallback();
		InitGlfw();
		SetupParameters();
		Log::Debug("GLFW initialized.");
	}

	void GlfwLoader::SetupErrorCallback()
	{
		glfwSetErrorCallback([](int error, const char *description)
		{
			Log::Error("GLFW error code {}: {}", error, description);
		});
	}

	void GlfwLoader::InitGlfw()
	{
		if (!glfwInit())
		{
			throw GlfwException("GLFW cannot be initialized.");
		}
	}

	void GlfwLoader::SetupParameters()
	{
		glfwWindowHint(GLFW_SAMPLES, 4);
	}

	void GlfwLoader::Shutdown()
	{
		Log::Debug("GLFW terminate.");
		glfwTerminate();
		Log::Debug("GLFW terminated.");
	}
}