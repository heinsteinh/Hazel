#include "GuiContext.h"

#include "imgui.h"

#include "GuiConfiguration.h"
#include "GuiStyle.h"

namespace Hazel
{
	GuiContext::GuiContext()
	{
		IMGUI_CHECKVERSION();
		context = ImGui::CreateContext();
		ImGui::SetCurrentContext(context);
		GuiConfiguration::SetDefaultConfiguration();
		GuiStyle::SetDefaultStyle();
	}

	GuiContext::~GuiContext()
	{
		ImGui::DestroyContext(context);
	}

	void GuiContext::MakeCurrent()
	{
		ImGui::SetCurrentContext(context);
	}
}