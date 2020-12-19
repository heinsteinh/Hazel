#pragma once

namespace Hazel
{
	enum class EventCategory
	{
		None = 0,
		Window = 1,
		Input = 2,
		Keyboard = 4,
		Mouse = 8,
		MouseButton = 16
	};

	constexpr EventCategory operator|(EventCategory left, EventCategory right)
	{
		return static_cast<EventCategory>(static_cast<int>(left) | static_cast<int>(right));
	}

	constexpr bool operator&(EventCategory left, EventCategory right)
	{
		return static_cast<int>(left) & static_cast<int>(right);
	}
}