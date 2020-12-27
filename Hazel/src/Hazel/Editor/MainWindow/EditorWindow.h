#pragma once

#include "imgui.h"

namespace Hazel
{
	class EditorWindow
	{
	private:
		bool fullScreen = true;

	public:
		void Begin(const char *label);
		void End();

		void SetFullScreen(bool fullScreen)
		{
			this->fullScreen = fullScreen;
		}

	private:
		void SetupViewport();
		void PushWindowStyle();
		void BeginWindow(const char *label);
		void PopWindowStyle();
		void ActivateDockSpace();
	};
}