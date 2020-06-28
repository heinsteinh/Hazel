#pragma once

#include "Hazel/Window/Window.h"

namespace ImGui
{
	struct ImGuiContext;
}

namespace Hazel
{
	class ImGuiContext
	{
	private:
		ImGui::ImGuiContext *context = nullptr;

	public:
		ImGuiContext(const Window &window);
		~ImGuiContext();

		void MakeCurrent();

	private:
		void Init(const Window &window);
		void SetupAppearance();
		int GetConfigurationFlags();
		void Shutdown();
	};
}