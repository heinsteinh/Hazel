#pragma once

#include "imgui.h"

#include "Hazel/Core/Input/MouseButton.h"
#include "Hazel/Editor/Widgets/PopupSettings.h"

namespace Hazel
{
	class PopupFlags
	{
	public:
		static ImGuiPopupFlags GetFlags(const PopupSettings &settings)
		{
			ImGuiPopupFlags flags = ImGuiPopupFlags_None;
			if (!settings.OpenOverItem)
			{
				flags |= ImGuiPopupFlags_NoOpenOverItems;
			}
			flags |= GetMouseButtonFlag(settings.MouseButton);
			return flags;
		}

		static ImGuiPopupFlags GetMouseButtonFlag(MouseButton button)
		{
			switch (button)
			{
			case MouseButton::Left:
				return ImGuiPopupFlags_MouseButtonLeft;
			case MouseButton::Right:
				return ImGuiPopupFlags_MouseButtonRight;
			case MouseButton::Middle:
				return ImGuiPopupFlags_MouseButtonMiddle;
			}
			return ImGuiPopupFlags_None;
		}
	};
}