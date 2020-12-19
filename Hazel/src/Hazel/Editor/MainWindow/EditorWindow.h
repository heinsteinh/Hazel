#pragma once

#include "imgui.h"

#include "EditorMenu.h"

namespace Hazel
{
	class EditorWindow
	{
	private:
		bool fullScreen = true;
		EditorMenu menu;

	public:
		bool WantQuit() const
		{
			return menu.WantQuit();
		}

		void SetFullScreen(bool fullScreen)
		{
			this->fullScreen = fullScreen;
		}

		void Begin(const char *label);
		void End();

	private:
		void SetupViewport();
		void PushWindowStyle();
		void BeginWindow(const char *label);
		void PopWindowStyle();
		void ActivateDockSpace();
	};
}