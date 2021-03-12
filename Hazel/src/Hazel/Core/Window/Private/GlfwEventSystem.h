#pragma once

struct GLFWwindow;

namespace Hazel
{
	class GlfwEventReceiver;

	class GlfwEventSystem
	{
	public:
		static void RemoveCallbacks(GLFWwindow *window);
		static void SetupCallbacks(GLFWwindow *window, GlfwEventReceiver &receiver);

	private:
		static GlfwEventReceiver &GetReceiver(GLFWwindow *window);
	};
}