#pragma once

struct ImGuiContext;

namespace Hazel
{
	class ImGuiContext
	{
	private:
		::ImGuiContext *context = nullptr;

	public:
		ImGuiContext() = default;
		~ImGuiContext();

		void Init();
		void Shutdown();
		void MakeCurrent();

	private:
		void SetupAppearance();
		int GetConfigurationFlags();
	};
}