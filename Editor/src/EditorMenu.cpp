#include "EditorMenu.h"

#include "imgui.h"

namespace Hazel
{
	void EditorMenu::Draw()
	{
		if (ImGui::BeginMenuBar())
		{
			if (ImGui::BeginMenu("File"))
			{
				if (ImGui::MenuItem("Quit", "Ctrl+Q"))
				{
					open = false;
				}
				ImGui::EndMenu();
			}
			ImGui::EndMenuBar();
		}
	}
}