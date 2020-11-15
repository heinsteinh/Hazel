#include "ImGuiContextHolder.h"

#include "imgui.h"

namespace Hazel
{
	ImGuiContextHolder::ImGuiContextHolder()
	{
		IMGUI_CHECKVERSION();
		context = ImGui::CreateContext();
		ImGui::SetCurrentContext(context);
		SetupAppearance();
	}

	ImGuiContextHolder::~ImGuiContextHolder()
	{
		ImGui::DestroyContext(context);
	}

	void ImGuiContextHolder::MakeCurrent()
	{
		ImGui::SetCurrentContext(context);
	}

	void ImGuiContextHolder::SetupAppearance()
	{
		ImGui::StyleColorsDark();
		ImGui::GetIO().ConfigFlags = GetConfigurationFlags();
		ImGui::GetStyle().WindowRounding = 0.0f;
		ImGui::GetStyle().Colors[ImGuiCol_WindowBg].w = 1.0f;
	}

	int ImGuiContextHolder::GetConfigurationFlags()
	{
		return ImGuiConfigFlags_NavEnableKeyboard
			| ImGuiConfigFlags_DockingEnable
			| ImGuiConfigFlags_ViewportsEnable;
	}
}