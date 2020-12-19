#pragma once

namespace Hazel
{
	enum class EventType
	{
		Unknown,
		WindowClose,
		WindowResize,
		KeyPress,
		KeyRelease,
		KeyType,
		MouseButtonPress,
		MouseButtonRelease,
		MouseScroll,
		MouseMove
	};
}