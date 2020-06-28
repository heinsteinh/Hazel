#include "ImGuiContext.h"

#include "imgui.h"
#include "examples/imgui_impl_glfw.h"
#include "examples/imgui_impl_opengl3.h"

#include "GLFW/glfw3.h"

namespace Hazel
{
	ImGuiContext::ImGuiContext(const Window &window)
	{
		Init(window);
	}

	ImGuiContext::~ImGuiContext()
	{
		Shutdown();
	}

	void ImGuiContext::MakeCurrent()
	{
		ImGui::SetCurrentContext(context);
	}

	void ImGuiContext::Init(const Window &window)
	{
		IMGUI_CHECKVERSION();
		context = ImGui::CreateContext();
		MakeCurrent();
		SetupAppearance();
		ImGui_ImplGlfw_InitForOpenGL(window.GetHandle(), true);
		ImGui_ImplOpenGL3_Init("#version 410");
	}

	void ImGuiContext::SetupAppearance()
	{
		ImGui::StyleColorsDark();
		ImGui::GetIO().ConfigFlags = GetConfigurationFlags();
		ImGui::GetStyle().WindowRounding = 0.0f;
		ImGui::GetStyle().Colors[ImGuiCol_WindowBg].w = 1.0f;
	}

	int ImGuiContext::GetConfigurationFlags()
	{
		return ImGuiConfigFlags_NavEnableKeyboard
			| ImGuiConfigFlags_DockingEnable
			| ImGuiConfigFlags_ViewportsEnable;
	}

	void ImGuiContext::Shutdown()
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext(context);
		context = nullptr;
	}
}