#pragma once

struct GLFWwindow;
struct ImGuiContext;

namespace Hazel
{
	class ImGuiDrawingContext
	{
	private:
		GLFWwindow *window = nullptr;
		ImGuiContext *context = nullptr;

	public:
		ImGuiDrawingContext(GLFWwindow *window);
		~ImGuiDrawingContext();

		void Init();
		void MakeCurrent();
		void Shutdown();

	private:
		void SetupAppearance();
		int GetConfigurationFlags();
	};
}