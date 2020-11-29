#pragma once

struct ImGuiContext;

namespace Hazel
{
	class ImGuiContextHolder
	{
	private:
		ImGuiContext *context;

	public:
		ImGuiContextHolder();
		~ImGuiContextHolder();

		void MakeCurrent();

	private:
		void SetupAppearance();
		int GetConfigurationFlags();
	};
}