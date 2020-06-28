#include "Input.h"

#include "GLFW/glfw3.h"

#include "GlfwKeyMap.h"

namespace Hazel
{
	Input::Input(Window &window)
		: window(window.GetHandle())
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

	MousePosition Input::GetMousePosition() const
	{
		double x, y;
		glfwGetCursorPos(window, &x, &y);
		return {static_cast<float>(x), static_cast<float>(y)};
	}
}