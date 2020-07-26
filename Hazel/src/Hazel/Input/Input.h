#pragma once

#include "Key.h"
#include "MouseButton.h"

struct GLFWwindow;

namespace Hazel
{
	class Input
	{
	private:
		GLFWwindow *window = nullptr;

	public:
		Input(GLFWwindow *window);

		bool IsKeyPressed(Key key) const;
		bool IsMouseButtonPressed(MouseButton button) const;
		glm::vec2 GetMousePosition() const;
	};
}