#pragma once

#include "imgui.h"

#include "Hazel/Scene/Scene.h"

namespace Hazel
{
	class EntityPanelPopup
	{
	private:
		static constexpr ImGuiPopupFlags flags = ImGuiPopupFlags_MouseButtonRight
			| ImGuiPopupFlags_NoOpenOverItems;

	public:
		void Draw(Scene &scene)
		{
			if (ImGui::BeginPopupContextWindow(nullptr, flags))
			{
				if (ImGui::MenuItem("Create Empty Entity"))
				{
					scene.CreateEntity().AddComponent<TagComponent>("New Entity");
				}
				ImGui::EndPopup();
			}
		}
	};
}