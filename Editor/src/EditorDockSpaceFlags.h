#pragma once

#include "imgui.h"

namespace Hazel
{
	class EditorDockSpaceFlags
	{
	public:
		static constexpr ImGuiWindowFlags GetWindowFlags(bool fullScreen, ImGuiDockNodeFlags dockSpaceFlags)
		{
			auto windowFlags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
			if (fullScreen)
			{
				windowFlags |= GetFullScreenFlags();
			}
			if (dockSpaceFlags & ImGuiDockNodeFlags_PassthruCentralNode)
			{
				windowFlags |= ImGuiWindowFlags_NoBackground;
			}
			return windowFlags;
		}

		static constexpr ImGuiWindowFlags GetFullScreenFlags()
		{
			return ImGuiWindowFlags_NoTitleBar
				| ImGuiWindowFlags_NoCollapse
				| ImGuiWindowFlags_NoResize
				| ImGuiWindowFlags_NoMove
				| ImGuiWindowFlags_NoBringToFrontOnFocus
				| ImGuiWindowFlags_NoNavFocus;
		}
	};
}