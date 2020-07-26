#pragma once

struct GLFWwindow;
struct ImGuiContext;

namespace Hazel
{
	class ImGuiContext
	{
	private:
		GLFWwindow *window = nullptr;
		::ImGuiContext *context = nullptr;

	public:
		ImGuiContext(GLFWwindow *window);
		~ImGuiContext();

		void Init();
		void MakeCurrent();
		void Shutdown();

	private:
		void SetupAppearance();
		int GetConfigurationFlags();
	};
}