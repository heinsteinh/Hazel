#pragma once

#include "imgui.h"

#include "EditorMenu.h"

namespace Hazel
{
	class EditorWindow
	{
	private:
		ImGuiDockNodeFlags dockSpaceFlags = ImGuiDockNodeFlags_None;
		ImGuiWindowFlags windowFlags = ImGuiWindowFlags_None;
		bool fullScreen = true;
		EditorMenu menu;

	public:
		void Begin();
		void End();

		bool IsOpen() const
		{
			return menu.IsOpen();
		}

	private:
		void SetupFlags();
		void SetupViewport();
		void BeginWindow();
		void ActivateDockSpace();
	};
}