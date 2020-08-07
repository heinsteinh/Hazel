#include "ImGuiContext.h"

#include "imgui.h"

namespace Hazel
{
	ImGuiContext::~ImGuiContext()
	{
		Shutdown();
	}

	void ImGuiContext::Init()
	{
		if (!context)
		{
			IMGUI_CHECKVERSION();
			ImGui::SetCurrentContext(context = ImGui::CreateContext());
			SetupAppearance();
		}
	}

	void ImGuiContext::Shutdown()
	{
		if (context)
		{
			ImGui::DestroyContext(std::exchange(context, nullptr));
		}
	}

	void ImGuiContext::MakeCurrent()
	{
		ImGui::SetCurrentContext(context);
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
}