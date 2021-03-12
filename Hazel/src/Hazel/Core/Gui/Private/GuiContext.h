#pragma once

#include "imgui.h"

#include "GuiConfiguration.h"
#include "GuiStyle.h"

namespace Hazel
{
	class GuiContext
	{
	private:
		ImGuiContext *context;

	public:
		GuiContext()
		{
			IMGUI_CHECKVERSION();
			context = ImGui::CreateContext();
			ImGui::SetCurrentContext(context);
			GuiConfiguration::SetDefaultConfiguration();
			GuiStyle::SetDefaultStyle();
		}

		~GuiContext()
		{
			ImGui::DestroyContext(context);
		}

		void MakeCurrent()
		{
			ImGui::SetCurrentContext(context);
		}
	};
}