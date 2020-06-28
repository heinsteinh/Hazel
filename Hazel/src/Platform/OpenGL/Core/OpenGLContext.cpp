#include "OpenGLContext.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "Platform/OpenGL/Utils/OpenGLLoader.h"

namespace Hazel
{
	OpenGLContext::OpenGLContext(const Window &window)
		: window(window.GetHandle())
	{
		MakeCurrent();
		static OpenGLLoader loader;
	}

	void OpenGLContext::MakeCurrent()
	{
		glfwMakeContextCurrent(window);
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(window);
	}
}