#pragma once

#include "glm/glm.hpp"

#include "Key.h"
#include "MouseButton.h"
#include "MousePosition.h"
#include "Hazel/Window/Window.h"

namespace Hazel
{
	class Input
	{
	private:
		GLFWwindow *window = nullptr;

	public:
		Input(Window &window);

		bool IsKeyPressed(Key key) const;
		bool IsMouseButtonPressed(MouseButton button) const;
		MousePosition GetMousePosition() const;
	};
}