#include "ImGuiDrawingContext.h"

#include "imgui.h"
#include "examples/imgui_impl_glfw.h"
#include "examples/imgui_impl_opengl3.h"

namespace Hazel
{
	ImGuiDrawingContext::ImGuiDrawingContext(GLFWwindow *window)
		: window(window)
	{
	}

	ImGuiDrawingContext::~ImGuiDrawingContext()
	{
		Shutdown();
	}

	void ImGuiDrawingContext::Init()
	{
		if (!context)
		{
			IMGUI_CHECKVERSION();
			ImGui::SetCurrentContext(context = ImGui::CreateContext());
			SetupAppearance();
			ImGui_ImplGlfw_InitForOpenGL(window, true);
			ImGui_ImplOpenGL3_Init("#version 410");
		}
	}

	void ImGuiDrawingContext::MakeCurrent()
	{
		ImGui::SetCurrentContext(context);
	}

	void ImGuiDrawingContext::Shutdown()
	{
		if (context)
		{
			ImGui_ImplOpenGL3_Shutdown();
			ImGui_ImplGlfw_Shutdown();
			ImGui::DestroyContext(context);
			context = nullptr;
		}
	}

	void ImGuiDrawingContext::SetupAppearance()
	{
		ImGui::StyleColorsDark();
		ImGui::GetIO().ConfigFlags = GetConfigurationFlags();
		ImGui::GetStyle().WindowRounding = 0.0f;
		ImGui::GetStyle().Colors[ImGuiCol_WindowBg].w = 1.0f;
	}

	int ImGuiDrawingContext::GetConfigurationFlags()
	{
		return ImGuiConfigFlags_NavEnableKeyboard
			| ImGuiConfigFlags_DockingEnable
			| ImGuiConfigFlags_ViewportsEnable;
	}
}