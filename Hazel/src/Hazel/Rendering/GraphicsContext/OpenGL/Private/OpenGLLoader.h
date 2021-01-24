#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "Hazel/Core/Logging/Log.h"
#include "OpenGLDebugger.h"
#include "GladException.h"

namespace Hazel
{
	class OpenGLLoader
	{
	public:
		OpenGLLoader()
		{
			if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			{
				throw GladException("Glad cannot be initialized.");
			}
			glEnable(GL_MULTISAMPLE);
			glEnable(GL_DEPTH_TEST);
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
#ifdef HZ_DEBUG
			static OpenGLDebugger debugger;
#endif
		}
	};
}