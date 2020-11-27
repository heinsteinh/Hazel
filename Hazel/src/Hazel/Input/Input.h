#pragma once

#include "Key.h"
#include "MouseButton.h"

namespace Hazel
{
	class Input
	{
	private:
		std::bitset<static_cast<size_t>(Key::Count)> keys;
		std::bitset<static_cast<size_t>(MouseButton::Count)> mouseButtons;
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

		constexpr bool IsMouseButtonPressed(MouseButton mouseButton) const
		{
			return mouseButtons[static_cast<size_t>(mouseButton)];
		}

		void SetMouseButtonPressed(MouseButton mouseButton, bool pressed)
		{
			mouseButtons[static_cast<size_t>(mouseButton)] = pressed;
		}

		constexpr glm::vec2 GetMousePosition() const
		{
			return mousePosition;
		}

		constexpr void SetMousePosition(const glm::vec2 &mousePosition)
		{
			this->mousePosition = mousePosition;
		}

		void ClearKeys()
		{
			keys.reset();
		}

		void ClearMouseButtons()
		{
			mouseButtons.reset();
		}

		void Clear()
		{
			ClearKeys();
			ClearMouseButtons();
		}
	};
}