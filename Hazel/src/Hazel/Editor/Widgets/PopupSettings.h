#pragma once

#include "Hazel/Core/Input/MouseButton.h"

namespace Hazel
{
	struct PopupSettings
	{
		MouseButton MouseButton = MouseButton::Right;
		bool OpenOverItem = true;
	};
}