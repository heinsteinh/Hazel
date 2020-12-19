#include "OpenGLLoader.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "Hazel/Core/Logging/Log.h"
#include "OpenGLDebugger.h"
#include "GladException.h"

namespace Hazel
{
	OpenGLLoader::OpenGLLoader()
	{
		LoadGlad();
		DisplayOpenGLInfo();
		SetupConfiguration();
		SetupDebugging();
	}

	void OpenGLLoader::LoadGlad()
	{
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			throw GladException("Glad cannot be initialized.");
		}
	}

	void OpenGLLoader::DisplayOpenGLInfo()
	{
		Log::Info("OpenGL version: {}", glGetString(GL_VERSION));
		Log::Info("OpenGL vendor: {}", glGetString(GL_VENDOR));
		Log::Info("OpenGL renderer: {}", glGetString(GL_RENDERER));
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
#ifdef HZ_DEBUG
		static OpenGLDebugger debugger;
#endif
	}
}