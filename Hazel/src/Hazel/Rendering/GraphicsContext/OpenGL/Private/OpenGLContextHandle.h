#pragma once

#include "GLFW/glfw3.h"

namespace Hazel
{
	class OpenGLContextHandle
	{
	private:
		static inline thread_local GLFWwindow *currentContext = nullptr;

		GLFWwindow *context = nullptr;

	public:
		static GLFWwindow *GetCurrentContext()
		{
			return currentContext;
		}

		static void SetCurrentContext(GLFWwindow *context)
		{
			currentContext = context;
		}

		OpenGLContextHandle() = default;

		OpenGLContextHandle(GLFWwindow *context)
			: context(context)
		{
		}

		void MakeCurrent() const
		{
			if (currentContext != context)
			{
				glfwMakeContextCurrent(context);
				currentContext = context;
			}
		}

		void Detach() const
		{
			if (currentContext == context)
			{
				glfwMakeContextCurrent(nullptr);
				currentContext = nullptr;
			}
		}

		operator GLFWwindow *() const
		{
			return context;
		}
	};
}