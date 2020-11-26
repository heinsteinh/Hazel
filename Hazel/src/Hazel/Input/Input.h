#pragma once

#include "Key.h"
#include "MouseButton.h"

namespace Hazel
{
	class Input
	{
	private:
		std::bitset<static_cast<size_t>(Key::Count)> keys;
		std::bitset<static_cast<size_t>(MouseButton::Count)> buttons;
		glm::vec2 mousePosition{0.0f};

	public:
		constexpr bool IsKeyPressed(Key key) const
		{
			return keys[static_cast<size_t>(key)];
		}

		void SetKeyPressed(Key key, bool pressed)
		{
			keys[static_cast<size_t>(key)] = pressed;
		}

		constexpr bool IsMouseButtonPressed(MouseButton button) const
		{
			return buttons[static_cast<size_t>(button)];
		}

		void SetMouseButtonPressed(MouseButton button, bool pressed)
		{
			buttons[static_cast<size_t>(button)] = pressed;
		}

		constexpr glm::vec2 GetMousePosition() const
		{
			return mousePosition;
		}

		constexpr void SetMousePosition(const glm::vec2 &mousePosition)
		{
			this->mousePosition = mousePosition;
		}
	};
}