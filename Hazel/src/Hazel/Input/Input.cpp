#include "Input.h"

#include "GLFW/glfw3.h"

#include "Helpers/GlfwKeyMap.h"

namespace Hazel
{
	Input::Input(GLFWwindow *window)
		: window(window)
	{
	}

	bool Input::IsKeyPressed(Key key) const
	{
		return glfwGetKey(window, GlfwKeyMap::GetNativeKey(key)) == GLFW_PRESS;
	}

	bool Input::IsMouseButtonPressed(MouseButton button) const
	{
		return glfwGetMouseButton(window, static_cast<int>(button)) == GLFW_PRESS;
	}

	glm::vec2 Input::GetMousePosition() const
	{
		double x, y;
		glfwGetCursorPos(window, &x, &y);
		return {static_cast<float>(x), static_cast<float>(y)};
	}
}