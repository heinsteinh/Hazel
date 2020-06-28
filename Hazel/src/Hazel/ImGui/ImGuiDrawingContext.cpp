#include "ImGuiDrawingContext.h"

#include "imgui.h"
#include "examples/imgui_impl_glfw.h"
#include "examples/imgui_impl_opengl3.h"

namespace Hazel
{
	ImGuiDrawingContext::ImGuiDrawingContext(const Window &window)
	{
		Init(window);
	}

	ImGuiDrawingContext::~ImGuiDrawingContext()
	{
		Shutdown();
	}

	void ImGuiDrawingContext::MakeCurrent()
	{
		ImGui::SetCurrentContext(context);
	}

	void ImGuiDrawingContext::Init(const Window &window)
	{
		IMGUI_CHECKVERSION();
		context = ImGui::CreateContext();
		MakeCurrent();
		SetupAppearance();
		ImGui_ImplGlfw_InitForOpenGL(window.GetHandle(), true);
		ImGui_ImplOpenGL3_Init("#version 410");
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

	void ImGuiDrawingContext::Shutdown()
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext(context);
		context = nullptr;
	}
}