#pragma once

#include "Hazel/Window/Window.h"

struct ImGuiContext;

namespace Hazel
{
	class ImGuiDrawingContext
	{
	private:
		ImGuiContext *context = nullptr;

	public:
		ImGuiDrawingContext(const Window &window);
		~ImGuiDrawingContext();

		void MakeCurrent();

	private:
		void Init(const Window &window);
		void SetupAppearance();
		int GetConfigurationFlags();
		void Shutdown();
	};
}