#pragma once

namespace Hazel
{
	enum class EventType
	{
		Unknown,
		WindowClose,
		WindowResize,
		WindowRefresh,
		KeyPress,
		KeyRelease,
		KeyType,
		MouseButtonPress,
		MouseButtonRelease,
		MouseScroll,
		MouseMove
	};
}