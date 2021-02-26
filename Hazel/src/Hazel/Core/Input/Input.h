#pragma once

#include <bitset>

#include <glm/glm.hpp>

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
		glm::vec2 mouseScrollOffset{0.0f};

	public:
		bool IsKeyPressed(Key key) const
		{
			return keys[static_cast<size_t>(key)];
		}

		void SetKeyPressed(Key key, bool pressed)
		{
			keys[static_cast<size_t>(key)] = pressed;
		}

		void ClearKeys()
		{
			keys.reset();
		}

		bool IsMouseButtonPressed(MouseButton mouseButton) const
		{
			return mouseButtons[static_cast<size_t>(mouseButton)];
		}

		void SetMouseButtonPressed(MouseButton mouseButton, bool pressed)
		{
			mouseButtons[static_cast<size_t>(mouseButton)] = pressed;
		}

		void ClearMouseButtons()
		{
			mouseButtons.reset();
		}

		const glm::vec2 &GetMousePosition() const
		{
			return mousePosition;
		}

		void SetMousePosition(const glm::vec2 &mousePosition)
		{
			this->mousePosition = mousePosition;
		}

		const glm::vec2 &GetMouseScrollOffset() const
		{
			return mouseScrollOffset;
		}

		void SetMouseScrollOffset(const glm::vec2 &mouseScrollOffset)
		{
			this->mouseScrollOffset = mouseScrollOffset;
		}

		void ClearMouseScrollOffset()
		{
			mouseScrollOffset = glm::vec2(0.0f);
		}

		void Clear()
		{
			ClearKeys();
			ClearMouseButtons();
			ClearMouseScrollOffset();
		}

		template<typename ...Args>
		bool IsKeyPressed(Key key, Args ...args) const
		{
			return IsKeyPressed(key) && IsKeyPressed(args...);
		}
	};
}