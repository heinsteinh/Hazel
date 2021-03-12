#pragma once

#include "GLFW/glfw3.h"

namespace Hazel
{
	class EventSystem
	{
	public:
		static void PollEvents()
		{
			glfwPollEvents();
		}
	};
}