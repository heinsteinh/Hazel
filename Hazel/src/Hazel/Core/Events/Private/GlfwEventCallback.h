#pragma once

#include "EventReceiver.h"

struct GLFWwindow;

namespace Hazel
{
	class GlfwEventCallback
	{
	private:
		static EventReceiver &GetReceiver(GLFWwindow *window);

	public:
		static void RemoveCallbacks(GLFWwindow *window);
		static void SetupCallbacks(GLFWwindow *window, EventReceiver &receiver);
	};
}