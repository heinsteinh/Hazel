#include "GuiContext.h"

#include "imgui.h"

namespace Hazel
{
	GuiContext::GuiContext()
	{
		IMGUI_CHECKVERSION();
		context = ImGui::CreateContext();
		ImGui::SetCurrentContext(context);
		ImGui::GetIO().ConfigFlags = GetConfigurationFlags();
		SetupAppearance();
	}

	GuiContext::~GuiContext()
	{
		ImGui::DestroyContext(context);
	}

	void GuiContext::MakeCurrent()
	{
		ImGui::SetCurrentContext(context);
	}

	void GuiContext::SetupAppearance()
	{
		ImGui::StyleColorsDark();
		ImGui::GetStyle().WindowRounding = 0.0f;
		ImGui::GetStyle().Colors[ImGuiCol_WindowBg].w = 1.0f;
	}

	int GuiContext::GetConfigurationFlags()
	{
		return ImGuiConfigFlags_NavEnableKeyboard
			| ImGuiConfigFlags_DockingEnable
			| ImGuiConfigFlags_ViewportsEnable;
	}
}