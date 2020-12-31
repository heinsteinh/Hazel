#pragma once

struct GLFWwindow;

namespace Hazel
{
	class GlfwEventReceiver;

	class GlfwEventSystem
	{
	private:
		static GlfwEventReceiver &GetReceiver(GLFWwindow *window);

	public:
		static void RemoveCallbacks(GLFWwindow *window);
		static void SetupCallbacks(GLFWwindow *window, GlfwEventReceiver &receiver);
	};
}