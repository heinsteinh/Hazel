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
			Log::Critical("Glad cannot be initialized.");
			exit(-1);
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
		static OpenGLDebugger debugger;
	}
}